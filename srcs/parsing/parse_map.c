/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:59:04 by ymsa              #+#    #+#             */
/*   Updated: 2026/03/04 15:59:04 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	**store_map(char *filename)
{
	char	**grid;
	int		lines;

	lines = count_map_lines(filename);
	if (lines <= 0)
		return (NULL);
	grid = malloc(sizeof(char *) * (lines + 1));
	if (!grid)
		return (NULL);
	if (!fill_grid(grid, filename))
		return (free_split(grid), NULL);
	return (grid);
}

static int	get_map_width(char **grid)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (grid[i])
	{
		len = ft_strlen(grid[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

static int	get_map_height(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
		i++;
	return (i);
}

void	parse_map(char *filename, t_data *data)
{
	data->map.grid = store_map(filename);
	if (!data->map.grid)
	{
		ft_putstr_fd("Error\nFailed to store map\n", 2);
		free_map(&data->map);
		exit(1);
	}
	data->map.height = get_map_height(data->map.grid);
	data->map.width = get_map_width(data->map.grid);
	if (!check_chars(data->map.grid))
		return (free_map(&data->map), exit(1));
	if (!find_player(data))
		return (free_map(&data->map), exit(1));
	set_camera_plane(&data->player);
	if (!check_map_closed(data))
		return (free_map(&data->map), exit(1));
}
