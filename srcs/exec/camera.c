#include "../../includes/cub3d.h"

void	set_camera_plane(t_player *p)
{
	p->plane_x = p->dir_y * FOV;
	p->plane_y = -p->dir_x * FOV;
}

