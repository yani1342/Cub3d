/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:58:43 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/24 17:22:10 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (s[len])
		len++;
	str = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	const char	*original = "Winter is coming";
	char	*copie = ft_strdup(original);

	if (copie == NULL)
	{
		printf("Erreur\n");
		return (1);
	}
	printf("Chaine originale : %s\n", original);
	printf("Chaine copiee : %s\n", copie);

	free(copie);
	return (0);
}
*/
