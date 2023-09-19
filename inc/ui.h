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

# define WIN_W 800
# define WIN_H 600
# define WIN_TITLE "MiniRT - By caalbert & bluiz-al | 42SP"

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
}	t_data;

void	img_pix_put(t_img *img, int x, int y, int color);
int		key_hook(int keycode, t_data *data);
int		close_hook(t_data *data);
void	write_pixels(t_img *img, int width, int height, int color);

#endif
