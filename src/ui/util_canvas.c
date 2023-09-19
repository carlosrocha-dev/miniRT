/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_canvas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:09:02 by caalbert          #+#    #+#             */
/*   Updated: 2023/09/18 23:23:21 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	return (0);
}

int	close_hook(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	write_pixels(t_img *img, int width, int height, int color)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < height)
	{
		while (x < width)
		{
			img_pix_put(img, x, y, color);
			x++;
		}
		y++;
	}
}
