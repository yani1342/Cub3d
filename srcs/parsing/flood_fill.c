/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:46:42 by ymsa              #+#    #+#             */
/*   Updated: 2026/03/06 12:46:42 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// on copie car flood fill va modifier la grille en marquant les cases visitées.
// On ne veut pas détruire la vraie carte — le jeu en a besoin après.

static char	**copy_grid(char **grid, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(grid[i]);
		if (!copy[i])
			return (free_split(copy), NULL);
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

// la carte n'est pas fermée → on retourne 0 (erreur).
// Si on tombe sur un '1' → mur → on s'arrête, c'est bon.
// Si on tombe sur 'V' → déjà visité → on s'arrête (évite boucle infinie).

static int	flood_fill(char **grid, int x, int y, int height)
{
	// Sorti du tableau = carte pas fermée
	if (y < 0 || y >= height || x < 0 || x >= (int)ft_strlen(grid[y]))
		return (0);
	// Mur = on s'arrête, c'est bon
	if (grid[y][x] == '1')
		return (1);
	// Déjà visité = on s'arrête
	if (grid[y][x] == 'V')
		return (1);
	// On marque la case comme visitée
	grid[y][x] = 'V';
	// On propage dans les 4 directions
	if (!flood_fill(grid, x + 1, y, height))
		return (0);
	if (!flood_fill(grid, x - 1, y, height))
		return (0);
	if (!flood_fill(grid, x, y + 1, height))
		return (0);
	if (!flood_fill(grid, x, y - 1, height))
		return (0);
	return (1);
}

// C'est la fonction appelée depuis parse_map.
// Elle orchestre la copie, le flood fill, et le nettoyage.

int	check_map_closed(t_data *data)
{
	char	**copy;
	int		result;
	int		px;
	int		py;

	copy = copy_grid(data->map.grid, data->map.height);
	if (!copy)
		return (0);
	// Position du joueur en cases entières
	px = (int)data->player.x;
	py = (int)data->player.y;
	result = flood_fill(copy, px, py, data->map.height);
	free_split(copy);
	if (!result)
		ft_putstr_fd("Error\nMap is not closed\n", 2);
	return (result);
}
