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

	rgb = ft_split(color_str, ',');
	if (!rgb)
		return (-1);
	if (!is_numeric(rgb[0]) || !is_numeric(rgb[1]) || !is_numeric(rgb[2]))
	{
		ft_putstr_fd("Error\nInvalid RGB value\n", 2);
		return (free_split(rgb), -1);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_split(rgb);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_putstr_fd("Error\nInvalid RGB value\n", 2);
		return (-1);
	}
	return ((r << 16) | (g << 8) | b);
}
