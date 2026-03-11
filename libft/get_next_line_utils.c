/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:35:44 by ymsa              #+#    #+#             */
/*   Updated: 2026/03/04 17:11:20 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*add;
	size_t	a;
	size_t	b;
	size_t	size;

	a = 0;
	b = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	add = (char *) malloc(sizeof(char) * (size + 1));
	if (!add)
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
