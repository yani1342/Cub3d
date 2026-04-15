/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:22:37 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/22 18:45:51 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cpy;

	i = 0;
	cpy = (unsigned char *)s;
	while (i < n)
	{
		if (cpy[i] == (unsigned char) c)
			return ((void *)(cpy + i));
		i++;
	}
	return (NULL);
}
/*

#include <stdio.h>

int	main(void)
{
	char	s[] = "abcdef";
	char	c = 'z';
	size_t	n = 5;

	char *result = (char *)ft_memchr(s, c, n);

	if (result!= NULL)
		printf("Le caractère '%c' trouvé ; %s\n", c, result);
	else 
		printf("Le caractère '%c' non trouvé dans les %zu premier ocets.\n", c, n);
	return (0);
}
*/
