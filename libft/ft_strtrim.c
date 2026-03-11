/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymsa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:16:12 by ymsa              #+#    #+#             */
/*   Updated: 2024/11/27 14:40:17 by ymsa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;

	if ((s1 || set) == '\0')
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	end = ft_strlen(s1);
	while (end && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, 0, end));
}
/*
int	main(void)
{
	char	*str = "rrrahhhhyggjjjggrsgg";
	char	*set = "grs";

	printf("String avant strtrim :%s", str);
	printf("\nString apres strtrim :%s", ft_strtrim(str, set));
	return (0);
}
*/
