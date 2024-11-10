/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:36:36 by dklockow          #+#    #+#             */
/*   Updated: 2024/03/06 21:30:05 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	ptr = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
#include <stdio.h>
int main(void)
{
    char *str = "abcd";
    printf("Original ptr: %p\nNew ptr %p\n", str, ft_strdup(str));
	printf("New value %s\n", ft_strdup(str));
}*/
