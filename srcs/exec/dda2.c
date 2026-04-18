/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 20:24:07 by marvin            #+#    #+#             */
/*   Updated: 2026/04/18 20:24:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3d.h"

void	dda_init_pos(t_dda *c)
{
	c->pos_x = c->game->player.x;
	c->pos_y = c->game->player.y;
	c->ray->map_x = (int)c->pos_x;
	c->ray->map_y = (int)c->pos_y;
}

void	dda_step_dist(t_dda *c)
{
	if (c->ray->ray_dir_x == 0)
		c->step_dist_x = 1e30;
	else
		c->step_dist_x = fabs(1.0 / c->ray->ray_dir_x);
	if (c->ray->ray_dir_y == 0)
		c->step_dist_y = 1e30;
	else
		c->step_dist_y = fabs(1.0 / c->ray->ray_dir_y);
}

void	dda_init_steps(t_dda *c)
{
	if (c->ray->ray_dir_x < 0)
	{
		c->step_x = -1;
	}
	else
	{
		c->step_x = 1;
	}
	if (c->ray->ray_dir_y < 0)
	{
		c->step_y = -1;
	}
	else
	{
		c->step_y = 1;
	}
}

void	dda_init_next_distances(t_dda *c)
{
	if (c->ray->ray_dir_x < 0)
		c->next_x = (c->pos_x - c->ray->map_x) * c->step_dist_x;
	else
		c->next_x = (c->ray->map_x + 1.0 - c->pos_x) * c->step_dist_x;
	if (c->ray->ray_dir_y < 0)
		c->next_y = (c->pos_y - c->ray->map_y) * c->step_dist_y;
	else
		c->next_y = (c->ray->map_y + 1.0 - c->pos_y) * c->step_dist_y;
}

void	dda_compute_perp_dist(t_dda *c)
{
	if (c->ray->side == 0)
		c->ray->perp_wall_dist = c->next_x - c->step_dist_x;
	else
		c->ray->perp_wall_dist = c->next_y - c->step_dist_y;
}
