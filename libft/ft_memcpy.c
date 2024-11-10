/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:40:45 by dklockow          #+#    #+#             */
/*   Updated: 2024/03/01 15:39:14 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;

	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	while (n > 0)
	{
		n--;
		cdest[n] = csrc[n];
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>

int     main(void)
{
 	char	s1[] = "abcde";
 	char	s2[] = "xxx"; 
 	
	printf("%s\n", (char *)ft_memcpy(s1, s2, 2));
	printf("%s\n", (char *)memcpy(s1, s2, 2));     
}*/
