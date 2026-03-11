/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:21:51 by ymsa              #+#    #+#             */
/*   Updated: 2024/12/01 17:03:26 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if ((s || f || (*s)) == '\0')
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int main()
{
	int 	tableau[] = {10, 20 , 30, 40};
	int	taille = sizeof(tableau) / sizeof(tableau[0]);

		printf("Index : %d, Valeur :%d", ft_striteri(tableau, taille));
	return (0);
}
*/
