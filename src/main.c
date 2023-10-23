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

int	render_scene(t_data *data, t_sphere sphere)
{
	int			x;
	int			y;
	t_ray		r;
	int			color;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			r = init_ray(point(0, 0, 0), vector(0, 0, -1));
			if (hit_sphere(sphere, r))
				color = sphere.color;
			else
				color = 0x000000;
			img_pix_put(&data->img, x, y, color);
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

	sphere = init_sphere(point(0, 0, -5), 1, 0xFF0000);
	render_scene(&data, sphere);
	return (0);
}
