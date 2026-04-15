/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:14:19 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/13 14:59:37 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nprt)
{
	int	res;
	int	signe;
	int	i;

	res = 0;
	i = 0;
	signe = 1;
	while ((nprt[i] == 32) || (nprt[i] >= 9 && nprt[i] <= 13))
		i++;
	if (nprt[i] == '-' || nprt[i] == '+')
	{
		if (nprt[i] == '-')
			signe = -1;
		i++;
	}
	while (nprt[i] >= '0' && nprt[i] <= '9')
	{
		res = res * 10 + nprt[i] - '0';
		i++;
	}
	return (res * signe);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*nprt;

	nprt = "     ---+--+1234ab56";
	printf("%d", ft_atoi(nprt));
	return (0);
}
*/
