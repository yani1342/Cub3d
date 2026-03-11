/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:47:53 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/27 16:11:42 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if ((s || f) == '\0')
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == 0)
		return (0);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char transform(unsigned int i, char c)
{
	if (i && c >= 'a' && c <= 'z')
			return (c - 32);
	return (c);
}

int main()
{
	char str1[] = "WINTER is coming";
	char* str2;
	str2 = ft_strmapi(str1, transform);

	if (str2)
	{
		printf("String avant strmapi : %s", str1);
		printf("\n String apres strmapi : %s\n", str2);
		free(str2);
	}
	else
		printf("erreur");
	return (0);
}
*/
