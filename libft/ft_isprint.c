/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:22:30 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/12 13:39:04 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int c)
{
	if (!(c >= 32 && c <= 126))
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
	if (ft_isprint(c))
		printf("le char '%c' est print\n",c);
	else
		printf("le char '%c' n'est pas print\n",c);
		
	c = 'P';
	if (ft_isprint(c))
		printf("le char '%c' est print\n",c);
	else
		printf("le char '%c' n'est pas print\n",c);
		
	c = '0';
	if (ft_isprint(c))
		printf("le char '%c' est print\n",c);
	else
		printf("le char '%c' n'est pas print\n",c);
		
	return (0);
}
*/
