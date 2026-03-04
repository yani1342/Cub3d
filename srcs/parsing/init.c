/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:48:37 by ymsa              #+#    #+#             */
/*   Updated: 2026/02/25 10:48:37 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_map_data(t_data *data)
{
	data->map.grid = NULL;
	data->map.no_path = NULL;
	data->map.so_path = NULL;
	data->map.we_path = NULL;
	data->map.ea_path = NULL;
	data->map.floor_col = -1; //-1 indique que la couleur n'est pas encore mise
	data->map.ceil_col = -1; // ces deux -1 sont une securité anti doublon
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->player.x = 0;
	data->player.y = 0;
	data->player.dir_x = 0;
	data->player.dir_y = 0;
	data->player.angle = 0;
}

