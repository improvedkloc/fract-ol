/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:59:20 by dklockow          #+#    #+#             */
/*   Updated: 2024/03/03 23:48:43 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	src_len = 0;
	i = 0;
	while (dest_len < size && dest[dest_len])
		dest_len++;
	while (src[src_len])
		src_len++;
	while (src[i] && dest_len + 1 + i < size)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (dest_len + i < size)
		dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*
#include<stdio.h>
int	main(void)
{
	char destination[20] = "Hello, evv ";
    	char *source = "world!";

    	unsigned int n  = ft_strlcat(destination, source, 15);

    	printf("Concatenated string: %s\n", destination);
    	printf("Total length: %i\n", n);
}*/
