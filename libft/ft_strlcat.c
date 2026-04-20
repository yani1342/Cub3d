/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:42:37 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/22 16:19:42 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	d;
	size_t	s;

	d = 0;
	while (dst[d] != '\0' && d < n)
		d++;
	if (d == n)
		return (n + ft_strlen(src));
	s = 0;
	while (src[s] != '\0' && d + s < n - 1)
	{
		dst[d + s] = src[s];
			s++;
	}
	if (d + s < n)
		dst[d + s] = '\0';
	return (d + ft_strlen(src));
}
/*
#include <stdio.h>
int main(void)
{
	char src[] = "Bienvenue a 42 !";
	char dst[20] = "";
	size_t size = 20;
	size_t resultat; 

	resultat = ft_strlcat(dst, src, size);
	printf("Source: %s\nDestination: %s\nLongueur: %zu\n", src, dst, resultat);

	return 0;
}
*/
