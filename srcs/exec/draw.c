/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 20:24:16 by marvin            #+#    #+#             */
/*   Updated: 2026/04/18 20:24:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3d.h"

void	set_camera_plane(t_player *p)
{
	p->plane_x = p->dir_y * FOV;
	p->plane_y = -p->dir_x * FOV;
}

void	draw_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = data->img.addr + (y * data->img.line_len) + (x * data->img.bpp / 8);
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
			color = data->map.ceil_col;
		else
			color = data->map.floor_col;
		x = 0;
		while (x < WIN_WIDTH)
		{
			draw_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	frame_maker(t_data *data)
{
	draw_floor_ceiling(data);
	rays_columns(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0,
		0);
}
