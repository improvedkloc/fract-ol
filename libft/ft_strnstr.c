/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:59:20 by dklockow          #+#    #+#             */
/*   Updated: 2024/03/06 18:48:48 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*to_find;

	str = (char *)big;
	to_find = (char *)little;
	if (*to_find == '\0')
		return ((char *)str);
	if (len == 0 || *str == '\0')
		return (0);
	j = 0;
	while (*str && j < len)
	{
		i = 0;
		while (str[i] == to_find[i] && j + i < len)
		{
			if (to_find[i + 1] == '\0')
				return (str);
			i++;
		}
		str++;
		j++;
	}
	return (NULL);
}
/*
#include<stdio.h>
#include<string.h>
int	main(void)
{
	char *destination = "Hello, evvvvvvvvvvvvvvvv ";
    	char *source = "ev";

    	printf("Found string: %s\n", ft_strnstr(destination, source, -1));
	//printf("Original: %s\n", strnstr(destination, source, 0));
}*/