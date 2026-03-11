/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <ymsa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:40:56 by ymsa              #+#    #+#             */
/*   Updated: 2026/02/26 10:31:16 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_copy(char const *str, char delimiteur)
{
	size_t	len;
	size_t	i;
	char	*word;

	len = 0;
	i = 0;
	while (str[len] && str[len] != delimiteur)
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	if (len == 0)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	ft_free(char **str)
{
	size_t	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free (str);
}

static char	**ft_fill_words(const char *s, char c, size_t count)
{
	char	**resultat;
	size_t	i;
	char	*word;

	i = 0;
	resultat = (char **)malloc((count + 1) * sizeof(char *));
	if (!resultat)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			word = ft_copy(s, c);
			if (!(word))
				return (ft_free(resultat), NULL);
			resultat[i++] = word;
			while (*s && *s != c)
				s++;
		}
		else
		s++;
	}
	resultat[i] = NULL;
	return (resultat);
}

char	**ft_split(char const *s, char c)
{
	const char	*tmp;
	size_t		word_count;
	char		**result;

	if (!s)
		return (NULL);
	tmp = s;
	word_count = 0;
	while (*tmp)
	{
		while (*tmp == c)
			tmp++;
		if (*tmp)
		{
			word_count++;
			while (*tmp && *tmp != c)
				tmp++;
		}
	}
	result = ft_fill_words(s, c, word_count);
	return (result);
}
/*
int	main(void)
{
	char *s = " Winteriscoming";
	char	c = ' ';
	char **result = ft_split(s, c);
	size_t	i;
	
	i = 0;
	if(!result)
	{
		printf("Erreur");
		return (0);
	}
	while (result[i])
	{
		printf("Mot %zu:%s\n", i + 1, result[i]);
		i++;
	}
	ft_free(result);
	return (0);
}
*/
