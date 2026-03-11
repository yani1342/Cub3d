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
# define TILE_SIZE 32 // taille d'une case sur la minimap
# define ESC 65307
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define LEFT 65361
# define RIGHT 65363
# define SPEED 0.1      // vitesse de déplacement
# define ROT_SPEED 0.05 // vitesse de rotation
# define MM_MARGIN 10

typedef struct s_player
{
	double		x;// Position X précise sur la carte
	double		y;// Position Y précise sur la carte
	double		dir_x;// Vecteur de direction (X)
	double		dir_y; // Vecteur de direction (Y)
	double		angle; // Angle de vue en radians
}	t_player;

typedef struct s_map
{
	char	**grid;
	int	width;   // Largeur max de la carte
	int 	height;  // Hauteur de la carte
	char 	*no_path;
	char 	*so_path;
	char	*we_path;
	char	*ea_path;
	void	*no_tex;
	void	*so_tex;
	void	*we_tex;
	void	*ea_tex;
	int	floor_col; // Couleur du sol (format RGB)
	int	ceil_col;  // Couleur du plafond (format RGB)
} t_map;

typedef struct s_img // MLX
{
	void *img_ptr;
	char *addr;   // adresse mémoire des pixels
	int bpp;      // bits par pixel
	int line_len; // longueur d'une ligne en octets
	int endian;   // ordre des octets
} t_img;

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	t_img img;
	t_map map;
	t_player player;
}	t_data;
// Tu pourras ajouter t_ray ici normalement

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

#endif
