/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:43:18 by caalbert          #+#    #+#             */
/*   Updated: 2023/09/25 10:31:43 by caalbert         ###   ########.fr       */
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

int	main(int c, char **v)
{
	t_data	data;
	int		color;

	color = 0x00ff00;
	if (validate_args(c) || has_scene_is_valid(v[1]))
		return (1);
	printf("%s\n", v[1]);
	window(&data);
	fill_img_window(&data, color);
	mlx_hook(data.win_ptr, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win_ptr, 17, 1L << 0, close_hook, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
