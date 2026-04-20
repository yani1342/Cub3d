/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:11:28 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/24 18:11:31 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
	write (fd, "\n", 1);
}
/*
#include <fcntl.h>
int	main(void)
{
	int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
	ft_putendl_fd("qss", fd);
	ft_putendl_fd("qss", fd);
	close(fd);
	return (0);
}
*/
