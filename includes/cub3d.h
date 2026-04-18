/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2026/02/25 09:25:28 by marvin            #+#    #+#             */
/*   Updated: 2026/02/25 09:25:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define TILE_SIZE 32 // échelle de la minimap en pixels (une case = 1 unité grille de la map) un carré de 32x32 pixels
# define ESC 65307
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100 
# define LEFT 65361
# define RIGHT 65363 
# define SPEED 0.1      // vitesse de déplacement
# define ROT_SPEED 0.05 // vitesse de rotation
# define MM_MARGIN 10 // taille de la marge de carte de la minimap
# define FOV 0.66
# define HIT_NORTH 0 
# define HIT_SOUTH 1
# define HIT_EAST 2
# define HIT_WEST 3

typedef struct s_player
{
	double		x;// Position X précise sur la carte
	double		y;// Position Y précise sur la carte
	double		dir_x;// Vecteur de direction du joueur (là ou il regarde en (X))
	double		dir_y; // Vecteur de direction du joueur (là ou il regarde en (Y))
	double		plane_x; // Vecteur plan caméra (X) sert à fixer la largeur du champ de vision (FOV)
	double		plane_y; // Vecteur plan caméra(Y) sert à fixer la hauteur du champ de vision (FOV)
}	t_player;

typedef struct s_ray
{
	double	ray_dir_x; // Vecteur direction du rayon (X)
	double	ray_dir_y; // Vecteur direction du rayon (Y)
	int		map_x; // où en ait l'avancer du rayon sur l'axe X
	int		map_y; // où en ait l'avancer du rayon sur l'axe Y
	int		side; //lorsqu'un rayon touche un mur en X ou Y
	double	perp_wall_dist; // Distance perpendiculaire entre le rayon et le mur
	int		hit_wall; // face touchee: N/S/E/W
}	t_ray;

typedef struct s_img // MLX
{
	void *img_ptr; // Pointeur vers l'image
	char *addr;   // adresse mémoire des pixels
	int bpp;      // bits par pixel
	int line_len; // longueur d'une ligne en octets
	int endian;  //Endianness de l'image = endianness du système d'exploitation
	int width; // largeur de l'image
	int height; // hauteur de l'image
} t_img;

typedef struct s_tex_column
{
	int		start;
	int		end;
	t_img	*tex;
	int		tex_x;
	double	step;
	double	pos;
}	t_tex_column;

typedef struct s_map
{
	char	**grid; // Grille de la carte
	int	    width;   // Largeur de la carte 
	int 	height;  // Hauteur de la carte
	char 	*no_path; // Chemin de la texture du nord
	char 	*so_path; // Chemin de la texture du sud
	char	*we_path; // Chemin de la texture de l'ouest
	char	*ea_path; // Chemin de la texture de l'est
	t_img	no_tex; // Texture du nord
	t_img	so_tex; // Texture du sud
	t_img	we_tex; // Texture de l'ouest
	t_img	ea_tex; // Texture de l'est
	int	floor_col; // Couleur du sol (format RGB)
	int	ceil_col;  // Couleur du plafond (format RGB)
} t_map;

typedef struct s_data
{
	void *mlx_ptr; // Pointeur vers le serveur graphique MLX (X11 sur Linux) 
	void *win_ptr; // Pointeur vers la fenêtre
	t_img img; // Image de la fenêtre
	t_map map; // Carte
	t_player player; // Joueur
}	t_data;

typedef struct s_dda
{
	t_data	*game; // Pointeur vers les données du jeu
	t_ray	*ray; // Pointeur vers le rayon
	double	pos_x; // c'est l'équilavent x dans t_player, mais c'est le nom d'usage en matière de DDA
	double	pos_y; // c'est l'équilavent y dans t_player, mais c'est le nom d'usage en matière de DDA
	double	step_dist_x; //distance rayon pour traverser une case sur l'axe X
	double	step_dist_y; //distance rayon pour traverser une case sur l'axe Y
	double	next_x; // distance jusqu'a la prochaine grille en X 
	double	next_y; // distance jusqu'a la prochaine grille en Y
	int		step_x; // case par case du rayon sur l'axe X
	int		step_y; // case par case du rayon sur l'axe Y
}	t_dda;

void	init_map_data(t_data *data);
void	validate_arguments(int argc, char **argv);
void	parse_file(char *filename, t_data *data);
void	parse_map(char *filename, t_data *data);
void	init_mlx(t_data *data);
void	draw_minimap(t_data *data);
void	handle_movement(int keycode, t_data *data);
void	free_map(t_map *map);
void	free_data(t_data *data);
void	error_exit(t_data *data, char *msg);
void	load_textures(t_data *data);
t_img	*get_hit_wall_tex(t_data *data, t_ray *ray);

char	*skip_spaces(char *str);

int	check_extension(char *filename);
int	check_all_elements(t_data *data);
int	process_texture(t_data *data, char *trimmed);
int	process_color(t_data *data, char *trimmed);
int	parse_rgb(char *color_str);
int	check_chars(char **grid);
int	find_player(t_data *data);
int	check_map_closed(t_data *data);
int	handle_keypress(int keycode, t_data *data);
int	handle_close(t_data *data);
int	fill_grid(char **grid, char *filename);
int	count_map_lines(char *filename);

void	free_split(char **tab);
void	drain_gnl(int fd);

void	set_camera_plane(t_player *p);
void	draw_floor_ceiling(t_data *data);
void	draw_pixel(t_data *data, int x, int y, int color);
void	ray_direction(t_player *player, int x, t_ray *ray);
void	rays_columns(t_data *data);
void	frame_maker(t_data *data);
void	dda_cast(t_data *data, t_ray *ray);
void	dda_init_pos(t_dda *c);
void	dda_step_dist(t_dda *c);
void	dda_init_steps(t_dda *c);
void	dda_init_next_distances(t_dda *c);
void	dda_loop(t_dda *c);
void	dda_compute_perp_dist(t_dda *c);
void	draw_wall_slice(t_data *data, int x, t_ray *ray);
void	draw_tex_columns(t_data *data, t_ray *ray, int x, t_tex_column *seg);

#endif
