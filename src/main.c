/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:43:18 by caalbert          #+#    #+#             */
/*   Updated: 2023/10/23 08:30:51 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	render_pixel(t_ray r, t_sphere sphere, t_light light)
{
	float	t;
	t_tuple	hit_point;
	t_tuple	normal;
	t_tuple	light_direction;
	float	light_dot_normal;
	int		color;

	if (hit_sphere(sphere, r, &t))
	{
		hit_point = point_at_parameter(r, t);
		normal = normalize(subtract(hit_point, sphere.center));
		// light_direction = normalize(subtract(light.position, hit_point));
		light_direction = normalize(subtract(hit_point, light.position));


		// if (dot(light_direction, normal) > 0)
		if (dot(light_direction, normal) < 0)
		{
			light_dot_normal = dot(light_direction, normal);
			float diffuse = light_dot_normal * light.intensity;
			color = mult_color(sphere.color, diffuse);
			color = mult_color(color, light.color);
		}
		else
			color = 0x000000;
	}
	else
		color = 0x000000;
	return (color);
}


int	render_scene(t_data *data, t_sphere sphere, t_light light)
{
	int		x;
	int		y;
	t_ray	r;
	float	aspect_ratio = (float)data->dim.image_width / (float)data->dim.image_height;

	y = 0;
	while (y < data->dim.image_height)
	{
		x = 0;
		while (x < data->dim.image_width)
		{
			float dir_x = (2.0f * x / data->dim.image_width - 1.0f) * aspect_ratio;
			float dir_y = 1.0f - 2.0f * y / data->dim.image_height;
			r = init_ray(point(0, 0, 0), normalize(vector(dir_x, dir_y, -1)));
			img_pix_put(&data->img, x, y, render_pixel(r, sphere, light));
			x++;
		}
		y++;
	}
	return (0);
}

int	main(void)
{
	t_data		data;
	t_sphere	sphere;
	t_light		light;

	window(&data);
	light.position = point(-1, 1, -1); // Defina a posição da luz
	light.color = 0xFFFFFF; // Luz branca
	light.intensity = 0.9; // Intensidade da luz
	sphere = init_sphere(point(0, 0, -5), 1, 0xFFFFFF);
	render_scene(&data, sphere, light);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_hook(data.win_ptr, 17, 0L, close_hook, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
