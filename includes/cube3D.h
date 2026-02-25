#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

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

typedef enum e_bool
{
    FALSE,
    TRUE
}   t_bool;

#endif
