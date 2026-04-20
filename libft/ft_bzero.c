/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:54:37 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/19 12:41:06 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
/*
#include <stddef.h>
#include <strings.h>
#include <stdio.h>

int	main(void)
{
	char buffer[6] = {'a', 'b', 'c', 'd', 'e', '\0'};
	
	printf("Caractere avant bzero : '%s'\n", buffer);
	
	ft_bzero(buffer, 3);
	
	printf("Caractere apres bzero (caractères individuels) : ");
    	for (int i = 0; i < 5; i++)
    	{
    	    if (buffer[i] == 0)
    	        printf("[/0]");
    	    else
    	        printf("[%c]", buffer[i]);
    	}
	return (0);
}
*/
