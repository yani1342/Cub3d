/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:57:12 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/22 19:28:37 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*l1;
	unsigned char	*l2;

	l1 = (unsigned char *)s1;
	l2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (l1[i] != l2[i])
			return (l1[i] - l2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char	a[] = "fa";
	char	b[] = "fb";

	printf("resultat : %d", ft_memcmp(a, b, 10));
}
*/
