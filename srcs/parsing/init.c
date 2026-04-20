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

void	init_texture(t_img *tex)
{
	tex->img_ptr = NULL;
	tex->addr = NULL;
	tex->bpp = 0;
	tex->line_len = 0;
	tex->endian = 0;
	tex->width = 0;
	tex->height = 0;
}

void	init_map_data(t_data *data)
{
	init_texture(&data->map.no_tex);
	init_texture(&data->map.so_tex);
	init_texture(&data->map.we_tex);
	init_texture(&data->map.ea_tex);
	data->map.grid = NULL;
	data->map.no_path = NULL;
	data->map.so_path = NULL;
	data->map.we_path = NULL;
	data->map.ea_path = NULL;
	data->map.floor_col = -1;
	data->map.ceil_col = -1;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->player.x = 0;
	data->player.y = 0;
	data->player.dir_x = 0;
	data->player.dir_y = 0;
	data->player.plane_x = 0;
	data->player.plane_y = 0;
}

void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_putstr_fd("Error\nMLX init failed\n", 2);
		exit(1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"cub3D");
	if (!data->win_ptr)
	{
		ft_putstr_fd("Error\nWindow creation failed\n", 2);
		exit(1);
	}
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.img_ptr)
	{
		ft_putstr_fd("Error\nImage creation failed\n", 2);
		exit(1);
	}
	data->img.addr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bpp, &data->img.line_len, &data->img.endian);
}
