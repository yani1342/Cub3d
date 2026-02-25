/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:47:32 by ymsa              #+#    #+#             */
/*   Updated: 2026/02/25 10:47:32 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*skip_spaces(char *str)
{
	if (!str)
		return (NULL);
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	return (str);
}
// Trouve le texte "./textures/briques_rouges.xpm" 
// et le met de côté
char	*extract_path(char *line)
{
	char	*path;
	int		i;

	if (!line)
		return (NULL);
    i = 0;
	while (line[i] && (line[i] != ' ' && line[i] != '\t'))
		i++;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	path = ft_strtrim(&line[i], " \n\t\v\r\f");
	return (path);
}

static int	assign_texture(char **texture_path, char *trimmed)
{
	if (*texture_path != NULL)
	{
		ft_putstr_fd("Error\nDuplicate texture found\n", 2);
		return (0);
	}
	*texture_path = extract_path(trimmed);
	if (!*texture_path)
		return (0);
	return (1);
}

int	process_texture(t_data *data, char *trimmed)
{
	if (ft_strncmp(trimmed, "NO ", 3) == 0)
		return (assign_texture(&data->map.no_path, trimmed));
	else if (ft_strncmp(trimmed, "SO ", 3) == 0)
		return (assign_texture(&data->map.so_path, trimmed));
	else if (ft_strncmp(trimmed, "WE ", 3) == 0)
		return (assign_texture(&data->map.we_path, trimmed));
	else if (ft_strncmp(trimmed, "EA ", 3) == 0)
		return (assign_texture(&data->map.ea_path, trimmed));
	return (1); 
}

void	parse_file(char *filename, t_data *data)
{
	int		fd;
	char	*line;
	char	*trimmed;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nCannot open file\n", 2);
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		trimmed = skip_spaces(line);
		if (!process_texture(data, trimmed))
        {
			free(line);
			close(fd);
			exit(1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
