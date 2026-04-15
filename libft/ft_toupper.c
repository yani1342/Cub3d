/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:00:07 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/18 11:46:15 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 97 && c <= 122))
		return (c - 32);
	else
		return (c);
}	
/*
#include <stdio.h>

int main(void) 
{
	
	int	c = 'b';

    printf("Resultat: %c\n", ft_toupper(c));

    return (0);
}
*/
