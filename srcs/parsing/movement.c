/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:44:14 by ymsa              #+#    #+#             */
/*   Updated: 2026/03/06 15:44:14 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Avant de bouger, on vérifie que la nouvelle case n'est pas un mur '1'.
// Si c'est un mur, on bloque le mouvement.
static int	is_wall(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || map_y >= data->map.height)
		return (1);
	if (map_x < 0 || map_x >= (int)ft_strlen(data->map.grid[map_y]))
		return (1);
	return (data->map.grid[map_y][map_x] == '1');
}

static void	move_forward_back(t_data *data, int forward)
{
	double	new_x;
	double	new_y;
	int		dir;

	if (forward)
		dir = 1;
	else
		dir = -1;
	new_x = data->player.x + data->player.dir_x * SPEED * dir;
	new_y = data->player.y + data->player.dir_y * SPEED * dir;
	if (!is_wall(data, new_x, data->player.y))
		data->player.x = new_x;
	if (!is_wall(data, data->player.x, new_y))
		data->player.y = new_y;
}

// Pour aller à gauche/droite, on utilise le vecteur
// perpendiculaire à la direction du regard.
// Perpendiculaire de (dir_x, dir_y) = (-dir_y, dir_x)

static void	move_side(t_data *data, int right)
{
	double	new_x;
	double	new_y;
	int		dir;

	if (right)
		dir = 1;
	else
		dir = -1;
	new_x = data->player.x + (-data->player.dir_y) * SPEED * dir;
	new_y = data->player.y + data->player.dir_x * SPEED * dir;
	if (!is_wall(data, new_x, data->player.y))
		data->player.x = new_x;
	if (!is_wall(data, data->player.x, new_y))
		data->player.y = new_y;
}

// Tourner = faire pivoter le vecteur direction d'un angle.
// C'est exactement ce que font cos/sin — ils tournent un vecteur.
// old_dir_x et old_dir_y = ancienne direction
// Après rotation :
//   dir_x = old_x * cos(turn) - old_y * sin(turn)
//   dir_y = old_x * sin(turn) + old_y * cos(turn)

static void	rotate(t_data *data, int right)
{
	double	old_dir_x;
	double	old_plane_x;
	double	turn;

	if (right)
		turn = -ROT_SPEED;
	else
		turn = ROT_SPEED;
	old_dir_x = data->player.dir_x;
	data->player.dir_x = old_dir_x * cos(turn) - data->player.dir_y * sin(turn);
	data->player.dir_y = old_dir_x * sin(turn) + data->player.dir_y * cos(turn);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = old_plane_x * cos(turn) - data->player.plane_y
		* sin(turn);
	data->player.plane_y = old_plane_x * sin(turn) + data->player.plane_y
		* cos(turn);
}

void	handle_movement(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		move_forward_back(data, 1);
	else if (keycode == S_KEY)
		move_forward_back(data, 0);
	else if (keycode == D_KEY)
		move_side(data, 1);
	else if (keycode == A_KEY)
		move_side(data, 0);
	else if (keycode == RIGHT)
		rotate(data, 1);
	else if (keycode == LEFT)
		rotate(data, 0);
}
