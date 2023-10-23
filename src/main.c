/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:43:18 by caalbert          #+#    #+#             */
/*   Updated: 2023/10/22 21:01:56 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, WIN_TITLE);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
	&data->img.line_len, &data->img.endian);
}

void	fill_img_window(t_data *data, int color)
{
	write_pixels(&data->img, WIN_W, WIN_H, color);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, \
	0, 0);
}

int	main(void)
{
	t_data		data;
	// t_camera	camera;
	t_sphere	sphere;
	t_ray		r;
	int			x;
	int			y;
	int			color;

	// Initialize the camera, sphere and ray
	// camera = init_camera(70, (float)WIN_W / (float)WIN_H, 2.0, 1.0);
	sphere = init_sphere(point(0, 0, -5), 1, 0xFF0000);

	// Ray tracing
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			// Create the ray from the camera here, adjusting for your specific implementation
			r = init_ray(point(0, 0, 0), vector(0, 0, -1));
			// Collision test with sphere
			if (hit_sphere(sphere, r))
				color = sphere.color;
			else
				color = 0x000000;
			img_pix_put(&data.img, x, y, color);
			x++;
		}
		y++;
	}
	return (0);
}
