/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:24:47 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/24 16:56:05 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	byte;
	void	*ptr;

	byte = nmemb * size;
	if (size != 0 && ((byte / size) != nmemb))
		return (NULL);
	ptr = malloc(byte);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, byte);
	return (ptr);
}
/*
int	main()
{
	int	i = 0;

	int* arr = (int*)ft_calloc(5,sizeof(int));
	if (arr	== NULL)
	{
		printf("Echec\n");
		return (1);
	}

	printf("Contenu du tableau ;\n");
	for (i= 0; i < 5; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	free(arr);

	return (0);
}
*/
