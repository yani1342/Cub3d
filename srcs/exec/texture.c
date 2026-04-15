#include "../../includes/cub3d.h"

int	load_one_texture(t_data *data, t_img *tex, char *path)
{
	int	w;
	int	h;

	tex->img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path, &w, &h);
	if (!tex->img_ptr)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img_ptr,
			&tex->bpp, &tex->line_len, &tex->endian);
	tex->width = w;
	tex->height = h;
	return (1);
}


void	load_textures(t_data *data)
{
	if (!load_one_texture(data, &data->map.no_tex, data->map.no_path)
		|| !load_one_texture(data, &data->map.so_tex, data->map.so_path)
		|| !load_one_texture(data, &data->map.we_tex, data->map.we_path)
		|| !load_one_texture(data, &data->map.ea_tex, data->map.ea_path))
	{
		ft_putstr_fd("Error\nFailed to load textures\n", 2);
		free_data(data);
		exit(1);
	}
}

