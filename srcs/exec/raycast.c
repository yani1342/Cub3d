#include "../../includes/cub3d.h"

//calcul un rayon, pour une colonne x
void	ray_direction(t_player *player, int x, t_ray *ray)
{
	double	camera_x;

	camera_x = 2.0 * (double)x / (double)WIN_WIDTH - 1.0;
	ray->ray_dir_x = player->dir_x + player->plane_x * camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * camera_x;
}

//calcule le début et la fin de la tranche de mur à dessiner
static void	get_slice(t_ray *ray, int *draw_start, int *draw_end)
{
	int	line_height; //hauteur du mur

	if (ray->perp_wall_dist <= 0.0001)
		line_height = WIN_HEIGHT;
	else
		line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	*draw_start = -line_height / 2 + WIN_HEIGHT / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = line_height / 2 + WIN_HEIGHT / 2;
	if (*draw_end >= WIN_HEIGHT)
		*draw_end = WIN_HEIGHT - 1;
}

static int	wall_color(t_ray *ray)
{
	if (ray->hit_wall == HIT_NORTH)
		return (0x00CC3333); //rouge
	if (ray->hit_wall == HIT_SOUTH)
		return (0x00992222); //vert
	if (ray->hit_wall == HIT_EAST)
		return (0x003333CC); //bleu
	if (ray->hit_wall == HIT_WEST)
		return (0x00222299); //jaune
	if (ray->side == 0)
		return (0x00CC0000); //rouge
	return (0x00990000); //vert
}


//Dessine une tranche verticale de mur pour la colonne x.
void	draw_wall_slice(t_data *data, int x, t_ray *ray)
{
	int			draw_start;
	int			draw_end;
	int			y;
	int			color;
	t_img		*tex;
	t_tex_column	seg;

	get_slice(ray, &draw_start, &draw_end);  //calcule le début et la fin de la tranche de mur à dessiner
	tex = get_hit_wall_tex(data, ray); //récupère la texture du mur touché
	if (tex && tex->addr)
	{
		seg.start = draw_start;
		seg.end = draw_end;
		seg.tex = tex;
		draw_tex_columns(data, ray, x, &seg); //dessine la texture du mur du rayon x
		return ;
	}
	color = wall_color(ray);
	y = draw_start;
	while (y <= draw_end) //dessine la tranche de mur
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

