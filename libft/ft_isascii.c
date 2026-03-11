/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:11:19 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/12 13:20:16 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int c)
{
	if (!(c >= 0 && c <= 127))
		return (0);
	else
		return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	unsigned char	c;
	
	c = ')';
	if (ft_isascii(c))
		printf("le char '%c' est ascii\n",c);
	else
		printf("le char '%c' n'est pas ascii\n",c);
		
	c = 'P';
	if (ft_isascii(c))
		printf("le char '%c' est ascii\n",c);
	else
		printf("le char '%c' n'est pas ascii\n",c);
		
	c = '0';
	if (ft_isascii(c))
		printf("le char '%c' est ascii\n",c);
	else
		printf("le char '%c' n'est pas ascii\n",c);
		
	return (0);
}
*/
