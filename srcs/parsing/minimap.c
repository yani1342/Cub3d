/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:19:00 by ymsa              #+#    #+#             */
/*   Updated: 2026/03/06 13:19:00 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = data->img.addr + (y * data->img.line_len)
		+ (x * data->img.bpp / 8);
	*(unsigned int *)dst = color;
}

static void	draw_tile(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			put_pixel(data, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

static void	draw_player(t_data *data, int off_x, int off_y)
{
	int	px;
	int	py;
	int	i;
	int	j;

	px = off_x + (int)(data->player.x * TILE_SIZE) - 4;
	py = off_y + (int)(data->player.y * TILE_SIZE) - 4;
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			put_pixel(data, px + j, py + i, 0xFF0000);
			j++;
		}
		i++;
	}
}

static void	draw_tiles(t_data *data, int off_x, int off_y)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < (int)ft_strlen(data->map.grid[i]))
		{
			if (data->map.grid[i][j] == '1')
				color = 0x333333;
			else
				color = 0xAAAAAA;
			draw_tile(data, off_x + j * TILE_SIZE, off_y + i * TILE_SIZE, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_data *data)
{
	int	off_x;
	int	off_y;

	off_x = WIN_WIDTH - data->map.width * TILE_SIZE - MM_MARGIN;
	off_y = WIN_HEIGHT - data->map.height * TILE_SIZE - MM_MARGIN;
	draw_tiles(data, off_x, off_y);
	draw_player(data, off_x, off_y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
}
