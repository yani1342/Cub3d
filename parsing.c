/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:13:50 by ymsa              #+#    #+#             */
/*   Updated: 2026/02/25 10:13:50 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_all_elements(t_data *data)
{
	if (data->map.no_path && data->map.so_path && data->map.we_path
		&& data->map.ea_path && data->map.floor_col != -1
		&& data->map.ceil_col != -1)
		return (1);
	return (0);
}

static int	handle_line(t_data *data, char *line, int fd)
{
	char	*trimmed;

	trimmed = skip_spaces(line);
	if (trimmed[0] == '\0')
		return (1);
	if (!check_all_elements(data))
		return (handle_elements(data, trimmed, line, fd));
	if (is_duplicate(trimmed))
		exit_parsing_error(data, line, fd,
			"Error\nDuplicate element found\n");
	return (0);
}

static void	check_missing_elements(t_data *data, char *line, int fd)
{
	if (!check_all_elements(data))
	{
		ft_putstr_fd("Error\nMissing elements in .cub file\n", 2);
		if (line)
			free(line);
		drain_gnl(fd);
		close(fd);
		exit(1);
	}
}

void	parse_file(char *filename, t_data *data)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error\nCannot open file\n", 2), exit(1));
	line = get_next_line(fd);
	while (line)
	{
		if (!handle_line(data, line, fd))
			break ;
		free(line);
		line = get_next_line(fd);
	}
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
	check_missing_elements(data, line, fd);
	free(line);
	close(fd);
	parse_map(filename, data);
}
