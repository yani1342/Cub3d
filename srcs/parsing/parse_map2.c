/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:59:04 by ymsa              #+#    #+#             */
/*   Updated: 2026/03/09 11:46:17 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	process_line_count(char *line, int *in_map, int *count)
{
	char	*trimmed;

	trimmed = skip_spaces(line);
	if (!*in_map && (trimmed[0] == '1' || trimmed[0] == '0'))
		*in_map = 1;
	if (*in_map && trimmed[0] == '\0')
		return (ft_putstr_fd("Error\nEmpty line in map\n", 2), 0);
	if (*in_map)
		(*count)++;
	return (1);
}

static void	drain_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

int	count_map_lines(char *filename)
{
	int		fd;
	char	*line;
	int		count;
	int		in_map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	in_map = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!process_line_count(line, &in_map, &count))
{
    free(line);
    drain_gnl(fd);
    close(fd);
    return (-1);
}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static int	process_line_fill(char **grid, char *line, int *i, int *in_map)
{
	char	*trimmed;

	trimmed = skip_spaces(line);
	if (!*in_map && (trimmed[0] == '1' || trimmed[0] == '0'))
		*in_map = 1;
	if (*in_map && trimmed[0] == '\0')
		return (0);
	if (*in_map)
	{
		grid[*i] = ft_strtrim(line, "\n\r");
		if (grid[*i] && grid[*i][0] != '\0')
			(*i)++;
		else
			free(grid[*i]);
	}
	return (1);
}

int	fill_grid(char **grid, char *filename)
{
	int		fd;
	char	*line;
	int		i;
	int		in_map;

	fd = open(filename, O_RDONLY);
	i = 0;
	in_map = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!process_line_fill(grid, line, &i, &in_map))
			return (free(line), close(fd), 0);
		free(line);
		line = get_next_line(fd);
	}
	grid[i] = NULL;
	return (close(fd), 1);
}
