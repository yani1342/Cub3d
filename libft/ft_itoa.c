/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:12:56 by ymsa              #+#    #+#             */
/*   Updated: 2024/12/01 12:23:20 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(long nbr)
{	
	size_t		len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	size_t	size;
	char	*str;
	int		negative;

	nbr = n;
	negative = (nbr < 0);
	if (negative)
		nbr = -nbr;
	size = ft_len(nbr) + negative;
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		size--;
		str[size] = (nbr % 10) + '0';
		nbr /= 10;
		if (size == 0 && negative)
			str[size] = '-';
	}
	return (str);
}
/*
int	main(void)
{
	int	a;

	a = -545;
	printf("resultat :%s", ft_itoa(a));
	return (0);
}
*/
