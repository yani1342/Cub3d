/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:33:18 by ymsa              #+#    #+#             */
/*   Updated: 2026/03/09 11:24:23 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*init_empty_string(void)
{
	char	*str;

	str = (char *)malloc(1 * sizeof(char));
	if (str)
		str[0] = '\0';
	return (str);
}

char	*shift_string(char **str, size_t start)
{
	char	*temp;
	char	*line;

	line = ft_substr(*str, 0, start);
	if (!str || !*str)
		return (NULL);
	temp = ft_substr(*str, start, ft_strlen(*str) - start);
	if (temp)
	{
		free(*str);
		*str = temp;
	}
	return (line);
}

int	read_file_content(char **previous_content, int fd)
{
	char	*buffer;
	ssize_t	bytes_read;
	int		newline_found;
	char	*temp;

	if (!(*previous_content))
	*previous_content = init_empty_string();
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer || fd < 0 || BUFFER_SIZE < 0)
		return (free(buffer), 0);
	newline_found = 0;
	bytes_read = 1;
	while (!newline_found && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read >= 0)
		{
			buffer[bytes_read] = '\0';
			temp = ft_strjoin(*previous_content, buffer);
			free(*previous_content);
			*previous_content = temp;
			newline_found = (ft_strchr(*previous_content, '\n') != NULL);
		}
	}
	return (free(buffer), 1);
}

char	*get_next_line(int fd)
{
	static char	*previous_content;
	int			newline_position;
	char		*line;
	char		*newline_ptr;

	if (!read_file_content(&previous_content, fd))
		return (NULL);
	if (!previous_content)          // ← AJOUTER : guard contre NULL
		return (NULL);
	newline_ptr = ft_strchr(previous_content, '\n');
	if (newline_ptr)
		newline_position = newline_ptr - previous_content;
	else
		newline_position = -1;
	if (newline_position >= 0)
		line = shift_string(&previous_content, newline_position + 1);
	else
	{
		line = ft_substr(previous_content, 0, ft_strlen(previous_content));
		free(previous_content);
		previous_content = NULL;
	}
	if (!line || ft_strlen(line) == 0)
		return (free(line), NULL);
	return (line);
}
