/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:03:18 by dklockow          #+#    #+#             */
/*   Updated: 2024/03/03 21:14:09 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*uc1;
	unsigned char	*uc2;

	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (*uc1 == *uc2 && i < n - 1)
	{
		uc1++;
		uc2++;
		i++;
	}
	return (*uc1 - *uc2);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	s1[] = {0, 0, 127, 0};
	char	s2[] = {0, 0, 42, 0};
	size_t n = 4;

	printf("%i\n", ft_memcmp(s1, s2, n));
	printf("%i\n", memcmp(s1, s2, n));	
}*/