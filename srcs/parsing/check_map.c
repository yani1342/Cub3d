/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:28:17 by ymsa              #+#    #+#             */
/*   Updated: 2026/03/04 16:28:17 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ');
}

int	check_chars(char **grid)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (!is_valid_char(grid[i][j]))
			{
				ft_putstr_fd("Error\nInvalid character in map\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static void	set_player_dir(t_player *player, char dir)
{
	player->dir_x = 0;
	player->dir_y = 0;
	if (dir == 'N')
		player->dir_y = -1;
	else if (dir == 'S')
		player->dir_y = 1;
	else if (dir == 'E')
		player->dir_x = 1;
	else if (dir == 'W')
		player->dir_x = -1;
}

static int	handle_player(t_data *data, int i, int j, int *count)
{
	*count += 1;
	if (*count > 1)
	{
		ft_putstr_fd("Error\nMultiple players in map\n", 2);
		return (0);
	}
	data->player.x = j + 0.5;
	data->player.y = i + 0.5;
	set_player_dir(&data->player, data->map.grid[i][j]);
	data->map.grid[i][j] = '0';
	return (1);
}

int	find_player(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data->map.grid[i])
	{
		j = 0;
		while (data->map.grid[i][j])
		{
			if (ft_strchr("NSEW", data->map.grid[i][j]))
				if (!handle_player(data, i, j, &count))
					return (0);
			j++;
		}
		i++;
	}
	if (count == 0)
		return (ft_putstr_fd("Error\nNo player found in map\n", 2), 0);
	return (1);
}
