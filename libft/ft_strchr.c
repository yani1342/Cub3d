/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:10:41 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/18 14:29:12 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
int	main(void) 
{
	char	*str = "Winter is coming !";
	char	c = 'i';

	char *res = ft_strchr(str, c);
	if (res) 
	{
	printf("La chaine débutant par '%c' est: '%s'\n",c, res);
	} 
 
	else 
	{
	printf("Le caractère '%c' n'a pas été trouvé.\n", c);
	}
	return 0;
}
*/
