/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:27:37 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/25 14:50:07 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*malloc_check(void)
{
	char	*copie;

	copie = malloc(1);
	if (copie)
	{
		copie[0] = '\0';
		return (copie);
	}
	else
		return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		l;
	char				*copie;

	l = 0;
	if (!s)
		return (malloc_check());
	if (start >= ft_strlen(s))
		return (malloc_check());
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	copie = malloc(((int) len + 1) * sizeof(char));
	if (!copie)
		return (NULL);
	while (l < len)
	{
		copie[l] = s[start + l];
		l++;
	}
	copie[len] = '\0';
	return (copie);
}
/*
int	main(void)
{
	const char	*original = "Winter is coming";
	char	*copie = ft_substr(original, 3, 20);

	if (copie == NULL)
	{
		printf("Erreur\n");
		return (1);
	}
	printf("Chaine originale : %s\n", original);
	printf("Chaine copiee : %s\n", copie);

	//free(copie);
	return (0);
}
*/
