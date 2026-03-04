/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:25:28 by marvin            #+#    #+#             */
/*   Updated: 2026/02/25 09:25:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_player
{
    double  x;          // Position X précise sur la carte
    double  y;          // Position Y précise sur la carte
    double  dir_x;      // Vecteur de direction (X)
    double  dir_y;      // Vecteur de direction (Y)
    double  angle;      // Angle de vue en radians
}   t_player;

typedef struct s_map
{
    char    **grid;     // Ton tableau 2D (la carte)
    int     width;      // Largeur max de la carte
    int     height;     // Hauteur de la carte
    char    *no_path;   // Chemin texture Nord
    char    *so_path;   // Chemin texture Sud
    char    *we_path;   // Chemin texture Ouest
    char    *ea_path;   // Chemin texture Est
    int     floor_col;  // Couleur du sol (format RGB)
    int     ceil_col;   // Couleur du plafond (format RGB)
}   t_map;

typedef struct s_data
{
    void        *mlx_ptr;
    void        *win_ptr;
    t_map       map;
    t_player    player;
}   t_data;
//Tu pourras ajouter t_ray ici normalement

void	init_map_data(t_data *data);
void	validate_arguments(int argc, char **argv);
void	parse_file(char *filename, t_data *data);
void	parse_map(char *filename, t_data *data);

char	*skip_spaces(char *str);

int		check_extension(char *filename);
int		check_all_elements(t_data *data);
int		process_texture(t_data *data, char *trimmed);
int		process_color(t_data *data, char *trimmed);
int		parse_rgb(char *color_str);
int     check_chars(char **grid);
int	    find_player(t_data *data);

void	free_split(char **tab);

#endif