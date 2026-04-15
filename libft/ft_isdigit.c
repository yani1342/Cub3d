/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:46:52 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/12 12:53:25 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	if (!(c >= 48 && c <= 57))
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
	if (ft_isdigit(c))
		printf("le char '%c' est digit\n",c);
	else
		printf("le char '%c' n'est pas digit\n",c);
		
	c = 'P';
	if (ft_isdigit(c))
		printf("le char '%c' est digit\n",c);
	else
		printf("le char '%c' n'est pas digit\n",c);
		
	c = '0';
	if (ft_isdigit(c))
		printf("le char '%c' est digit\n",c);
	else
		printf("le char '%c' n'est pas digit\n",c);
		
	return (0);
}
*/
