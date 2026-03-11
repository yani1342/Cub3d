/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:34:50 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/18 10:59:08 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	if (!((c >= 65 && c <= 90) || (c >= 97 && c <= 122)))
		return (0);
	else
		return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	unsigned char	c;
	
	c = ';';
	if (ft_isalpha(c))
		printf("le char '%c' est alpha\n",c);
	else
		printf("le char '%c' n'est pas alpha\n",c);
		
	c = 'P';
	if (ft_isalpha(c))
		printf("le char '%c' est alpha\n",c);
	else
		printf("le char '%c' n'est pas alpha\n",c);
		
	c = '0';
	if (ft_isalpha(c))
		printf("le char '%c' est alpha\n",c);
	else
		printf("le char '%c' n'est pas alpha\n",c);
		
	return (0);
}
*/
