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
# define TILE_SIZE 32
# define ESC 65307
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100 
# define LEFT 65361
# define RIGHT 65363 
# define SPEED 0.1
# define ROT_SPEED 0.05
# define MM_MARGIN 10
# define FOV 0.66
# define HIT_NORTH 0 
# define HIT_SOUTH 1
# define HIT_EAST 2
# define HIT_WEST 3

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}	t_player;

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	int		side;
	double	perp_wall_dist;
	int		hit_wall;
}	t_ray;

typedef struct s_img
{
	void *img_ptr;
	char *addr;
	int bpp;
	int line_len;
	int endian;
	int width;
	int height;
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
	char	**grid;
	int	    width; 
	int 	height;
	char 	*no_path;
	char 	*so_path;
	char	*we_path;
	char	*ea_path;
	t_img	no_tex;
	t_img	so_tex;
	t_img	we_tex;
	t_img	ea_tex;
	int	floor_col;
	int	ceil_col;
} t_map;

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	t_img img;
	t_map map;
	t_player player;
}	t_data;

typedef struct s_dda
{
	t_data	*game;
	t_ray	*ray;
	double	pos_x;
	double	pos_y;
	double	step_dist_x;
	double	step_dist_y;
	double	next_x;
	double	next_y;
	int		step_x;
	int		step_y;
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
