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

static int	count_map_lines(char *filename)
{
	int		fd;
	char	*line;
	char	*trimmed;
	int		count;
	int		in_map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	in_map = 0;
	line = get_next_line(fd);
	while (line)
	{
		trimmed = skip_spaces(line);
		// On détecte le début de la carte, la première ligne qui commence par '1' ou '0'
		// (les textures/couleurs ne commencent jamais par ces caractères)
		if (!in_map && (trimmed[0] == '1' || trimmed[0] == '0'))
			in_map = 1;
		// Une fois qu'on est dans la carte, on compte chaque ligne
		if (in_map)
			count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

// get_next_line garde le '\n' à la fin de chaque ligne.
// Si on le garde, la carte sera pleine de '\n' parasites
// qui vont fausser toutes les vérifications de caractères après.
// ft_strtrim nettoie ça proprement.

static void	fill_grid(char **grid, char *filename)
{
	int		fd;
	char	*line;
	char	*trimmed;
	int		i;
	int		in_map;

	fd = open(filename, O_RDONLY);
	i = 0;
	in_map = 0;
	line = get_next_line(fd);
	while (line)
	{
		trimmed = skip_spaces(line);
		if (!in_map && (trimmed[0] == '1' || trimmed[0] == '0'))
			in_map = 1;
        // On stocke la ligne nettoyée dans le tableau
		if (in_map)
			grid[i++] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
	}
	grid[i] = NULL;
	close(fd);
}

static char	**store_map(char *filename)
{
	char	**grid;

	grid = malloc(sizeof(char *) * (count_map_lines(filename) + 1));
	// On alloue exactement le bon nombre de lignes + 1 pour le NULL final
	// Le NULL final permet de savoir où s'arrête le tableau
	// (comme une string se termine par '\0')
    if (!grid)
		return (NULL);
	fill_grid(grid, filename);
	return (grid);
}

// POURQUOI CALCULER LA WIDTH ?
// Toutes les lignes de la carte n'ont pas forcément la même longueur.
// Par exemple :
//   "111111"      <- 6 chars
//   "100001"      <- 6 chars
//   "1001"        <- 4 chars (ligne plus courte)
// On a besoin de connaître la largeur MAX pour :
// - Vérifier que la carte est bien fermée sur les bords
// - Allouer des tableaux de la bonne taille plus tard
// - Afficher la minimap correctement

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

// C'est la fonction principale appelée depuis parse_file.
// Elle orchestre tout : stocker la carte, calculer ses dimensions,
// et les sauvegarder dans data pour que tout le reste du programme
// puisse y accéder.

void	parse_map(char *filename, t_data *data)
{
	data->map.grid = store_map(filename);
	if (!data->map.grid)
	{
		ft_putstr_fd("Error\nFailed to store map\n", 2);
		exit(1);
	}
	// height = nombre de lignes = taille verticale de la carte
	// utilisé pour les boucles de vérification et la minimap
	data->map.height = count_map_lines(filename);
	// width = largeur max = taille horizontale de la carte
	data->map.width = get_map_width(data->map.grid);
    if (!check_chars(data->map.grid) || !find_player(data))
        exit(1);
}