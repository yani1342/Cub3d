/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 20:24:50 by marvin            #+#    #+#             */
/*   Updated: 2026/04/18 20:24:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3d.h"

t_img	*get_hit_wall_tex(t_data *data, t_ray *ray)
{
	if (ray->hit_wall == HIT_NORTH)
		return (&data->map.no_tex);
	if (ray->hit_wall == HIT_SOUTH)
		return (&data->map.so_tex);
	if (ray->hit_wall == HIT_WEST)
		return (&data->map.we_tex);
	if (ray->hit_wall == HIT_EAST)
		return (&data->map.ea_tex);
	return (NULL);
}

static void	get_tex_to_draw(t_data *data, t_ray *ray, t_img *tex, int *tex_x)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = data->player.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = data->player.x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	if (wall_x >= 1.0)
		wall_x = 1.0 - 1e-9;
	*tex_x = (int)(wall_x * (double)tex->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1
			&& ray->ray_dir_y < 0))
		*tex_x = tex->width - *tex_x - 1;
	if (tex->width > 0)
	{
		if (*tex_x < 0)
			*tex_x = 0;
		if (*tex_x >= tex->width)
			*tex_x = tex->width - 1;
	}
	else
		*tex_x = 0;
}

static int	get_pixel_tex(t_img *tex, int x, int y)
{
	char	*dst;

	if (!tex || !tex->addr || x < 0 || y < 0 || x >= tex->width
		|| y >= tex->height)
		return (0);
	dst = tex->addr + (y * tex->line_len) + (x * tex->bpp / 8);
	return (*(unsigned int *)dst);
}

static void	tex_loop(t_data *data, int x, t_tex_column *seg)
{
	int	tex_y;

	while (seg->start <= seg->end)
	{
		tex_y = (int)seg->pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= seg->tex->height)
			tex_y = seg->tex->height - 1;
		draw_pixel(data, x, seg->start, get_pixel_tex(seg->tex, seg->tex_x,
				tex_y));
		seg->pos += seg->step;
		seg->start++;
	}
}

void	draw_tex_columns(t_data *data, t_ray *ray, int x, t_tex_column *seg)
{
	int	line_height;
	int	start;

	start = seg->start;
	get_tex_to_draw(data, ray, seg->tex, &seg->tex_x);
	if (ray->perp_wall_dist <= 0.0001)
		line_height = WIN_HEIGHT;
	else
		line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	seg->step = 1.0 * seg->tex->height / line_height;
	seg->pos = (start - WIN_HEIGHT / 2 + line_height / 2) * seg->step;
	tex_loop(data, x, seg);
}
