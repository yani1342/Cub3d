/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 10:32:52 by ymsa              #+#    #+#             */
/*   Updated: 2026/02/26 10:32:52 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (!ft_isdigit(str[i]))
		return (0); 
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

// Transforme la chaine "220,100,0" en un code couleur int
int	parse_rgb(char *color_str)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(color_str, ',');	// On découpe la chaine en 3 morceaux
	if (!rgb)
		return (-1);
	// On convertit les morceaux en nombres
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	// On a plus besoin du tableau de texte, on le free
	free_split(rgb);
	//On vérifie que les nombres sont entre 0 et 255
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	// Formule de la MiniLibX pour fusionner RGB en un seul int
	return ((r << 16) | (g << 8) | b);
}