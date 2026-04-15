#include "../../includes/cub3d.h"

void	draw_floor_ceiling(t_data *data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y < WIN_HEIGHT / 2)
			color = data->map.ceil_col;   // plafond
		else
			color = data->map.floor_col;  // sol
		x = 0;
		while (x < WIN_WIDTH)
		{
			draw_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}

//calcul un rayon, pour une colonne x
void	ray_direction(t_player *player, int x, t_ray *ray)
{
	double	camera_x;

	camera_x = 2.0 * (double)x / (double)WIN_WIDTH - 1.0;
	ray->ray_dir_x = player->dir_x + player->plane_x * camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * camera_x;
}

//Dessine une tranche verticale de mur pour la colonne x.
void	draw_wall_slice(t_data *data, int x, t_ray *ray)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	y;
	int	color;
	if (ray->perp_wall_dist <= 0.0001)
		line_height = WIN_HEIGHT;
	else
		line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	draw_start = -line_height / 2 + WIN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + WIN_HEIGHT / 2;
	if (draw_end >= WIN_HEIGHT)
		draw_end = WIN_HEIGHT - 1;
	if (ray->side == 0)
		color = 0x00CC0000; /* mur vertical: rouge fonce */
	else
		color = 0x00990000; /* mur horizontal: rouge encore plus fonce */
	y = draw_start;
	while (y <= draw_end)
	{
		draw_pixel(data, x, y, color);
		y++;
	}
}

//c'est ça qui fait l'éventail de rayons
//ce qui permet de fabriquer l'image
void	rays_columns(t_data *data)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIN_WIDTH)
	{
		ray_direction(&data->player, x, &ray);
		dda_cast(data, &ray);
		draw_wall_slice(data, x, &ray);
		x++;
	}
}