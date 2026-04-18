/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:48:37 by ymsa              #+#    #+#             */
/*   Updated: 2026/02/25 10:48:37 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_texture(t_img *tex)
{
	tex->img_ptr = NULL;
	tex->addr = NULL;
	tex->bpp = 0;
	tex->line_len = 0;
	tex->endian = 0;
	tex->width = 0;
	tex->height = 0;
}

void	init_map_data(t_data *data)
{
	init_texture(&data->map.no_tex);
	init_texture(&data->map.so_tex);
	init_texture(&data->map.we_tex);
	init_texture(&data->map.ea_tex);
	data->map.grid = NULL;
	data->map.no_path = NULL;
	data->map.so_path = NULL;
	data->map.we_path = NULL;
	data->map.ea_path = NULL;
	data->map.floor_col = -1; //-1 indique que la couleur n'est pas encore mise
	data->map.ceil_col = -1;  // ces deux -1 sont une securité anti doublon
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->player.x = 0;
	data->player.y = 0;
	data->player.dir_x = 0;
	data->player.dir_y = 0;
	data->player.plane_x = 0;
	data->player.plane_y = 0;
}

// mlx_init ?
// C'est la première chose à faire avec MLX.
// Ça ouvre la connexion avec le serveur graphique (X11 sur Linux).
// Sans ça, impossible d'ouvrir une fenêtre ou de dessiner quoi que ce soit.

// mlx_new_window ?
// Ça crée la fenêtre visible à l'écran.
// WIN_WIDTH et WIN_HEIGHT sont définis dans cub3d.h (1280x720).

// mlx_new_image ?
// On crée une image en mémoire sur laquelle on va dessiner.
// C'est beaucoup plus rapide que de dessiner directement pixel
// par pixel dans la fenêtre.

// mlx_get_data_addr ?
// Elle nous donne l'adresse mémoire de l'image (addr).
// C'est grâce à ça qu'on peut modifier les pixels directement
// en mémoire avant d'envoyer l'image à la fenêtre.

void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_putstr_fd("Error\nMLX init failed\n", 2);
		exit(1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"cub3D");
	if (!data->win_ptr)
	{
		ft_putstr_fd("Error\nWindow creation failed\n", 2);
		exit(1);
	}
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.img_ptr)
	{
		ft_putstr_fd("Error\nImage creation failed\n", 2);
		exit(1);
	}
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
}
