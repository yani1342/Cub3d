/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:51:43 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/25 16:51:43 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*add;
	size_t	a;
	size_t	b;
	size_t	taille;

	a = 0;
	b = 0;
	taille = ft_strlen(s1) + ft_strlen(s2);
	add = (char *) malloc(sizeof(char) * (taille + 1));
	if (add == NULL)
		return (NULL);
	while (s1[a])
	{
		add[a] = s1[a];
		a++;
	}
	while (s2[b])
	{
		add [a + b] = s2[b];
		b++;
	}
	add[a + b] = '\0';
	return (add);
}
/*
int	main(void)
{
	char	*prefixe = "Winter ";
	char	*suffixe = "is coming";

	printf("Chaine : %s\n", ft_strjoin(prefixe, suffixe));

	return (0);
}
*/
