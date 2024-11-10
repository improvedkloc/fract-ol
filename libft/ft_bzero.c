/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:40:45 by dklockow          #+#    #+#             */
/*   Updated: 2024/03/01 14:47:18 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n > 0)
	{
		n--;
		ptr[n] = '\0';
	}
}
/*
#include <string.h>
#include <stdio.h>

int     main(void)
{
 	char	s1[] = "abcde";
	ft_bzero(s1, 4);
	printf("%c%c%c%c%c\n", s1[0], s1[1], s1[2], s1[3], s1[4]);     
}*/
