/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:57:13 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/12 13:04:54 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if (!((c >= 48 && c <= 57) || (c >= 65 && c <= 90)
			|| (c >= 97 && c <= 122)))
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
	if (ft_isalnum(c))
		printf("le char '%c' est alphamum\n",c);
	else
		printf("le char '%c' n'est pas alphamum\n",c);
		
	c = 'P';
	if (ft_isalnum(c))
		printf("le char '%c' est alphamum\n",c);
	else
		printf("le char '%c' n'est pas alphamum\n",c);
		
	c = '0';
	if (ft_isalnum(c))
		printf("le char '%c' est alphamum\n",c);
	else
		printf("le char '%c' n'est pas alphamum\n",c);
		
	return (0);
}
*/
