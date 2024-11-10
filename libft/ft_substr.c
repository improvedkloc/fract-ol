/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:23:13 by dklockow          #+#    #+#             */
/*   Updated: 2024/03/06 21:41:38 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen((char *)s))
	{
		str = (char *)malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	i = 0;
	if (ft_strlen((char *)s) - start < len)
		len = ft_strlen((char *)s) - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
int	main()
{
	char	*sep = "ala ma kota";
	
	printf("%s", ft_substr(sep, 4, 6));
}*/
