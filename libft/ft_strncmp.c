/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:03:18 by dklockow          #+#    #+#             */
/*   Updated: 2024/02/28 19:35:35 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && n > 1)
	{
		i++;
		n--;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	*s1 = "test\200";
	char	*s2 = "test\0";
	unsigned int n = 6;

	printf("%i\n", ft_strncmp(s1, s2, n));
	printf("%i\n", strncmp(s1, s2, n));	
}*/