/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 09:19:48 by ymsa              #+#    #+#             */
/*   Updated: 2026/02/26 09:19:48 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Compte le nombre de virgules dans la phrase, il en faut 2
static int	check_commas(char *str)
{
	int	i;
	int	count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count == 2)
		return (1);
	return (0);
}

// Extrait la chaîne de caractères après le 'F' ou le 'C'.
//  Ex: Si line = "F  220,100,0", ça renvoie "220,100,0"
static char	*extract_color_string(char *line)
{
	int		i;
	char	*color_str;

	if (!line)
		return (NULL);
	i = 0;
	// Saute la lettre 'F' ou 'C'
	while (line[i] && (line[i] != ' ' && line[i] != '\t'))
		i++;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	// Récupère tout le reste
	color_str = ft_strtrim(&line[i], " \n\t\v\r\f");
	return (color_str);
}

static int	assign_color(int *color_field, char *trimmed)
{
	char	*color_str;

	if (*color_field != -1)
	{
		ft_putstr_fd("Error\nDuplicate color found\n", 2);
		return (0);
	}
	color_str = extract_color_string(trimmed);
	if (!color_str)
		return (0);
	if (!check_commas(color_str))
		return (free(color_str), 0);
	*color_field = parse_rgb(color_str);
	free(color_str);
	if (*color_field == -1) /* Si parse_rgb renvoie -1, c'est que les chiffres sont faux */
		return (0);
	return (1);
}
//Pour le - 1 : Si floor_col n'est plus à -1, c'est que tu as déjà calculé une couleur pour le sol. 
// Donc, s'il y a un autre F dans le fichier, c'est un doublon = Erreur.

int	process_color(t_data *data, char *trimmed)
{
	if (ft_strncmp(trimmed, "F ", 2) == 0)
	{
		// On envoie l'adresse de floor_col pour la modifier directement
		if (!assign_color(&data->map.floor_col, trimmed))
			return (0);
	}
	else if (ft_strncmp(trimmed, "C ", 2) == 0)
	{
		// On envoie l'adresse de ceil_col
		if (!assign_color(&data->map.ceil_col, trimmed))
			return (0);
	}
	return (1); // Si ce n'est ni F ni C, on laisse passer
}
