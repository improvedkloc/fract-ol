/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:40:45 by dklockow          #+#    #+#             */
/*   Updated: 2024/03/03 21:01:54 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}
/*
#include <string.h>
#include <stdio.h>

int     main(void)
{
 	char	s1[] = "abcde";
 	char	s2 = 'x'; 
	
	printf("%s\n", (char *)ft_memset(s1, s2, 10));
	printf("%s\n", (char *)memset(s1, s2, 10));     
}*/
