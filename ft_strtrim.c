/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:12:25 by dklockow          #+#    #+#             */
/*   Updated: 2024/03/07 23:43:12 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_end(char const *s1, char const *set, size_t start)
{
	size_t	end;

	end = ft_strlen((char *)s1);
	while (end > start)
	{
		if (!ft_strchr(set, s1[end]))
			break ;
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!set)
		return (NULL);
	start = 0;
	while (s1[start])
	{
		if (!ft_strchr(set, s1[start]))
			break ;
		start++;
	}
	end = ft_find_end(s1, set, start);
	if (s1[start])
		end++;
	ptr = (char *)malloc((end - start + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (start < end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_strtrim("", "123"));
}*/