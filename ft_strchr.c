/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:36:36 by dklockow          #+#    #+#             */
/*   Updated: 2024/02/28 19:15:55 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr)
	{
		if (*ptr == (char)c)
			break ;
		ptr++;
	}
	if (*ptr == '\0' && c != '\0')
		return (0);
	return (ptr);
}
/*
#include<stdio.h>
int	main(void)
{
	char	*a = "tjhbdsjAA";
	printf("wynik funkcji to %s", ft_strchr(a, 't' + 256));	
}*/