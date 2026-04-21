/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:16:01 by ymsa              #+#    #+#             */
/*   Updated: 2026/04/20 20:25:49 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_identifier(char *str)
{
	if (ft_strncmp(str, "NO ", 3) == 0 || ft_strncmp(str, "SO ", 3) == 0
		|| ft_strncmp(str, "WE ", 3) == 0 || ft_strncmp(str, "EA ", 3) == 0
		|| ft_strncmp(str, "F ", 2) == 0 || ft_strncmp(str, "C ", 2) == 0)
		return (1);
	ft_putstr_fd("Error\nInvalid identifier or garbage line found\n", 2);
	return (0);
}

void	exit_parsing_error(t_data *data, char *line, int fd, char *msg)
{
	if (msg)
		ft_putstr_fd(msg, 2);
	free(line);
	free_map(&data->map, NULL);
	drain_gnl(fd);
	close(fd);
	exit(1);
}

int	handle_elements(t_data *data, char *trimmed, char *line, int fd)
{
	if (!is_valid_identifier(trimmed)
		|| !process_texture(data, trimmed)
		|| !process_color(data, trimmed))
	{
		exit_parsing_error(data, line, fd, NULL);
	}
	return (1);
}

int	is_duplicate(char *trimmed)
{
	return (ft_strncmp(trimmed, "NO ", 3) == 0
		|| ft_strncmp(trimmed, "SO ", 3) == 0
		|| ft_strncmp(trimmed, "WE ", 3) == 0
		|| ft_strncmp(trimmed, "EA ", 3) == 0
		|| ft_strncmp(trimmed, "F ", 2) == 0
		|| ft_strncmp(trimmed, "C ", 2) == 0);
}
