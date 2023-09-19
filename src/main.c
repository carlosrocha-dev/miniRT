/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:43:18 by caalbert          #+#    #+#             */
/*   Updated: 2023/09/19 08:58:23 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	errors(int argc)
{
	int	list;

	if (argc != 2)
	{
		printf("\033[33;1mError\n\033[0m");
		printf("\t An scene should be indicated! <./miniRT scene/scene.rt>\n");
		printf("You can use the following scenes:\n");
		list = system("ls -1 scene/");
		(void)list;
		return (0);
	}
	return (0);
}

int	main(int c, char **v)
{
	t_data	data;
	int		color;

	printf("%s\n", v[1]);
	errors(c);
	color = 0xff0000;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_W, WIN_H, WIN_TITLE);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIN_W, WIN_H);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, \
	&data.img.line_len, &data.img.endian);
	write_pixels(&data.img, WIN_W, WIN_H, color);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
	mlx_hook(data.win_ptr, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win_ptr, 17, 1L << 0, close_hook, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
	return (0);
}
