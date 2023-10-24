#include "../inc/minirt.h"

t_dimensions	compute_dimensions(void)
{
	t_dimensions	dim;

	dim.image_width = IMAGE_WIDTH;
	dim.image_height = (int)(IMAGE_WIDTH / (WIDTH_RATIO / HEIGHT_RATIO));
	if (dim.image_height < 1)
		dim.image_height = 1;
	dim.viewport_height = 2.0;
	dim.viewport_width = dim.viewport_height * \
	(double)(dim.image_width / dim.image_height);
	return (dim);
}

void	window(t_data *data)
{
	data->dim = compute_dimensions();

	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->dim.image_width, data->dim.image_height, WIN_TITLE);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, data->dim.image_width, data->dim.image_height);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
	&data->img.line_len, &data->img.endian);
}

void	fill_img_window(t_data *data, int color)
{
	write_pixels(&data->img, WIN_W, WIN_H, color);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, \
	0, 0);
}
