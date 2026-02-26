/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:17:26 by ymsa              #+#    #+#             */
/*   Updated: 2026/02/25 10:17:26 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//check la map
int	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5) //minimum "a.cub"
		return (0);
	if (ft_strncmp(&filename[len - 4], ".cub", 4) == 0)
		return (1);
	return (0);
}

void	validate_arguments(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./cub3D maps/map.cub\n", 2);
		exit(1);
	}
	if (!check_extension(argv[1]))
	{
		ft_putstr_fd("Error\nInvalid file extension. Expected .cub\n", 2);
		exit(1);
	}
}