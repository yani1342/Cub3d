/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:43:43 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/18 15:31:20 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
		dst[i] = src[i];
		i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
/*
#include <stdio.h>
#include <stddef.h>
int	main(void)
{
	char src[] = "Bienvenue a 42 !";
	char dst[24];
	size_t size;

	size = ft_strlcpy(dst, src, sizeof(dst));

	printf("Source: %s\nDestination: %s\nLongueur: %zu\n",
		src, dst, size);

	return 0;
}
*/
