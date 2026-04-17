/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2026/02/25 10:17:26 by ymsa              #+#    #+#             */
/*   Updated: 2026/02/25 10:17:26 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// check la map, minimum "a.cub"
int	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (ft_strncmp(&filename[len - 4], ".cub", 4) == 0)
		return (1);
	return (0);
}

int	is_readable(char *filename)
{
	// R_OK vérifie si le fichier possède la permission en lecture (Read)
	if (access(filename, R_OK) == 0)
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
	if (!is_readable(argv[1]))
	{
		ft_putstr_fd("Error\nCannot read file. Check permissions.\n", 2);
		exit(1);
	}
}
