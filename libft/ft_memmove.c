/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:38:06 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/19 19:05:56 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t n)
{
	char		*dest;
	char		*src;

	dest = (char *)d;
	src = (char *)s;
	if (d == s || n == 0)
		return (dest);
	if (dest < src)
	{
		while (n--)
			*dest++ = *src++;
	}
	else
	{
		dest += n;
		src += n;
		while (n--)
			*(--dest) = *(--src);
	}
	return ((void *)d);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	src[20] = "Bienvenue à 42 !";
	char	dest[20];
	size_t	n;

	n = 19;
	printf("Avant memmove :\n");
	printf("src: %s\n", (src));
	printf("dest: %s\n", (dest));

	ft_memmove(dest, src, n);

	printf("\nApres memmove :\n");
	printf("src: %s\n", (src));
	printf("dest: %s\n", (dest));
	
	
	char	buffer1[20] = "Bienvenue à 42 !";
	n = 10;;
	printf("\nAvant memmove (chevauchement src < dest) :\n");
	printf("buffer: %s\n", buffer1);

	ft_memmove(buffer1 + 5, buffer1, n);

	printf("\nApres memmove (chevauchement src < dest) :\n");
	printf("buffer: %s\n", buffer1);

	return (0);
}
*/
