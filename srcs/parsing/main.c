/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:09:26 by ymsa              #+#    #+#             */
/*   Updated: 2026/03/04 15:09:26 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	validate_arguments(argc, argv);
	init_map_data(&data);
	parse_file(argv[1], &data);
	parse_map(argv[1], &data);
	init_mlx(&data);
	draw_minimap(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}