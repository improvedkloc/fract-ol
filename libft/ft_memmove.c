/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:59:20 by dklockow          #+#    #+#             */
/*   Updated: 2024/03/03 23:23:51 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmpsrc;
	unsigned char	*tmpdest;

	tmpsrc = (unsigned char *)src;
	tmpdest = (unsigned char *)dest;
	if (tmpdest <= tmpsrc)
	{
		while (n--)
			*tmpdest++ = *tmpsrc++;
	}
	else
	{
		tmpsrc += n;
		tmpdest += n;
		while (n--)
			*(--tmpdest) = *(--tmpsrc);
	}
	return (dest);
}
/*
#include<string.h>
#include<stdio.h>
int	main(void)
{
	char dest[] = "Hello, evv";
    	char src[] = "world";

    	printf("%s\n", (char *)ft_memmove(dest, src, 5));
	printf("%s\n", (char *)memmove(dest, src, 5));
}*/
