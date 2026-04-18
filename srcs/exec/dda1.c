/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 20:23:55 by marvin            #+#    #+#             */
/*   Updated: 2026/04/18 20:23:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3d.h"

static void	dda_steps(t_dda *c)
{
	if (c->next_x < c->next_y)
	{
		c->next_x += c->step_dist_x;
		c->ray->map_x += c->step_x;
		c->ray->side = 0;
	}
	else
	{
		c->next_y += c->step_dist_y;
		c->ray->map_y += c->step_y;
		c->ray->side = 1;
	}
}

static int	is_wall_cell(t_data *data, int x, int y)
{
	int	row_len;

	if (y < 0 || y >= data->map.height)
		return (1);
	row_len = (int)ft_strlen(data->map.grid[y]);
	if (x < 0 || x >= row_len)
		return (1);
	return (data->map.grid[y][x] == '1');
}

static void	wall_reached(t_dda *c)
{
	if (c->ray->side == 0)
	{
		if (c->step_x > 0)
			c->ray->hit_wall = HIT_WEST;
		else
			c->ray->hit_wall = HIT_EAST;
	}
	else if (c->step_y > 0)
		c->ray->hit_wall = HIT_NORTH;
	else
		c->ray->hit_wall = HIT_SOUTH;
}

void	dda_loop(t_dda *c)
{
	int	hit;
	int	guard;

	hit = 0;
	guard = 0;
	while (hit == 0 && guard < c->game->map.width + c->game->map.height + 32)
	{
		guard++;
		dda_steps(c);
		if (is_wall_cell(c->game, c->ray->map_x, c->ray->map_y))
		{
			hit = 1;
			wall_reached(c);
		}
	}
}

void	dda_cast(t_data *data, t_ray *ray)
{
	t_dda	c;

	c.game = data;
	c.ray = ray;
	ray->hit_wall = -1;
	dda_init_pos(&c);
	dda_step_dist(&c);
	dda_init_steps(&c);
	dda_init_next_distances(&c);
	dda_loop(&c);
	dda_compute_perp_dist(&c);
}
