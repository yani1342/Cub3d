#include "../../includes/cub3d.h"

void	draw_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = data->img.addr + (y * data->img.line_len)
		+ (x * data->img.bpp / 8);
	*(unsigned int *)dst = color;
}

void	draw_floor_ceiling(t_data *data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y < WIN_HEIGHT / 2)
			color = data->map.ceil_col;   // plafond
		else
			color = data->map.floor_col;  // sol
		x = 0;
		while (x < WIN_WIDTH)
		{
			draw_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	render_frame(t_data *data)
{
	draw_floor_ceiling(data);
	rays_columns(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
}