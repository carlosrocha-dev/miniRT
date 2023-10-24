/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:10:21 by caalbert          #+#    #+#             */
/*   Updated: 2023/09/18 23:14:59 by caalbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# define EPSILON		0.00001
# define WIDTH_RATIO	16.0
# define HEIGHT_RATIO	9.0
# define IMAGE_WIDTH	800
# define PI				3.1415926535897932385
# define WIN_W			800
# define WIN_H			600
# define WIN_TITLE		"MiniRT - By caalbert & bluiz-al | 42SP"

typedef struct s_dimensions
{
	int		image_width;
	int		image_height;
	double	viewport_width;
	double	viewport_height;
}			t_dimensions;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_dimensions	dim;
}	t_data;

void	window(t_data *data);
void	img_pix_put(t_img *img, int x, int y, int color);
int		key_hook(int keycode, t_data *data);
int		close_hook(t_data *data);
void	write_pixels(t_img *img, int width, int height, int color);

#endif
