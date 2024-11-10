/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:59:20 by dklockow          #+#    #+#             */
/*   Updated: 2024/03/03 23:24:21 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size != '\0')
		dest[i] = '\0';
	return (src_len);
}
/*
#include<stdio.h>
#include<string.h>
int	main(void)
{
	char destination[7] = "Hello, ";
    char *source = "world!";

    unsigned int n  = ft_strlcpy(destination, source, 0);

    printf("Concatenated string: %s\n", destination);
    printf("Total length: %i\n", n);
}*/