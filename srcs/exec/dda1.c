#include "../../includes/cub3d.h"

//Avance le rayon d'une case à la fois sur l'axe X ou Y en fonction de la distance la plus courte.
static void	dda_steps(t_dda *c)
{
	if (c->next_x < c->next_y)
	{
		c->next_x += c->step_dist_x;
		c->ray->map_x += c->step_x;
		c->ray->side = 0;
	}
	else
	{
		c->next_y += c->step_dist_y;
		c->ray->map_y += c->step_y;
		c->ray->side = 1;
	}
}

//Vérifie si la case est un mur.
static int	is_wall_cell(t_data *data, int x, int y)
{
	int	row_len;

	if (y < 0 || y >= data->map.height) //sorti de la carte
		return (1);
	row_len = (int)ft_strlen(data->map.grid[y]);  
	if (x < 0 || x >= row_len) //sorti de la ligne
		return (1);
	return (data->map.grid[y][x] == '1'); //mur
}

//Détermine la face du mur touchée par le rayon.
static void	wall_reached(t_dda *c)
{
	if (c->ray->side == 0)
	{
		if (c->step_x > 0) //mur à gauche
			c->ray->hit_wall = HIT_WEST;
		else //mur à droite
			c->ray->hit_wall = HIT_EAST;
	}
	else if (c->step_y > 0) //mur en haut
		c->ray->hit_wall = HIT_NORTH;
	else //mur en bas
		c->ray->hit_wall = HIT_SOUTH;
}

//Boucle principale du DDA
// *c = dda struct pointer pour accéder aux variables internes du DDA
//construit le rayon case par case(step by step) jusqu'à ce qu'il touche un mur	
void	dda_loop(t_dda *c)
{
	int	hit; // 0 si le rayon n'a pas touché un mur, 1 sinon
	int	guard; // nombre de cases traversées par le rayon

	hit = 0;
	guard = 0;
	while (hit == 0 && guard < c->game->map.width + c->game->map.height + 32) // limite de cases traversées par le rayon	
	{
		guard++;
		dda_steps(c);
		if (is_wall_cell(c->game, c->ray->map_x, c->ray->map_y))
		{
			hit = 1;
			wall_reached(c);
		}
	}
}

//Cast le rayon  = lancer/tracer un rayon depuis le joueur dans une direction donnée jusquà ce qu'il touche un mur
void	dda_cast(t_data *data, t_ray *ray)
{
	t_dda	c;

	c.game = data;
	c.ray = ray;
	ray->hit_wall = -1; // Initialise la face touchee à -1 (aucune face touchee)
	dda_init_pos(&c);  // Initialise la position du rayon.
	dda_step_dist(&c); // Calcule la distance entre le rayon et le mur.
	dda_init_steps(&c); // Initialise le pas sur X et Y.
	dda_init_next_distances(&c); // Initialise les prochaines distances sur X et Y.
	dda_loop(&c); // Boucle principale du DDA.
	dda_compute_perp_dist(&c); // Calcule la distance perpendiculaire entre le rayon et le mur.	
}

