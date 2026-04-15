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