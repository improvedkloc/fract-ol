/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:40:45 by dklockow          #+#    #+#             */
/*   Updated: 2024/03/01 15:28:06 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	uc;

	i = 0;
	ptr = (unsigned char *)s;
	uc = c;
	while (i < n)
	{
		if (*ptr == uc)
			return ((void *)ptr);
		ptr++;
		i++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int     main(void)
{
 	char	s1[] = "abcde";
 	char	s2 = 'c';
 	
	printf("%s\n", (char *)ft_memchr(s1, s2, 4));
	printf("%p\n", (void *)ft_memchr(s1, s2, 2));     
}*/
