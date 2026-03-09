/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 10:06:25 by ymsa              #+#    #+#             */
/*   Updated: 2026/02/26 10:06:25 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_map(t_map *map)
{
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->we_path)
		free(map->we_path);
	if (map->ea_path)
		free(map->ea_path);
	if (map->grid)
		free_split(map->grid);
}

static void	free_mlx(t_data *data)
{
	if (data->img.img_ptr)                                          // ← AJOUTER
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr); 
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

void	free_data(t_data *data)
{
	free_map(&data->map);
	free_mlx(data);
}

void	error_exit(t_data *data, char *msg)
{
	ft_putstr_fd(msg, 2);
	free_map(&data->map);
	exit(1);
}