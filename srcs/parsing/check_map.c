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

// parcourir chaque case de grid et vérifier que les seuls caractères
// autorisés sont 0, 1, N, S, E, W ou " "
// en même temps on peut trouver le joueur — stocker
// sa position x, y et son orientation dans t_player

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
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

// Ces lettres indiquent à la fois :
//   - Sa position de départ (ligne i, colonne j)
//   - La direction vers laquelle il regarde au lancement
// Ex: regarder vers le Nord = aller vers le haut = dir_y négatif
//   N → (0, -1)
//   S → (0,  1)
//   E → (1,  0)
//   W → (-1, 0)

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

// POURQUOI +0.5 sur x et y ?
// La position du joueur est en cases (ex: case [2][3]).
// Mais le raycaster travaille en coordonnées précises (double).
// +0.5 place le joueur au centre de la case, pas dans son coin.
// Sans ça, le joueur serait collé contre un mur au départ.

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
	// On remplace N/S/E/W par '0' dans la grille
	// car c'est une case vide une fois le joueur extrait
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
