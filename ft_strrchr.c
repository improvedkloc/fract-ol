/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:36:36 by dklockow          #+#    #+#             */
/*   Updated: 2024/02/28 19:15:26 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*ptr;
	char	ch;

	ch = c;
	i = 0;
	ptr = (char *)str;
	if (ch == '\0')
		return (ptr + ft_strlen(ptr));
	while (ptr[i])
	{
		if (ptr[i] == ch)
		{
			ptr += i;
			i = 0;
		}
		i++;
	}
	if (ptr[0] != ch && ch != '\0')
		return (0);
	return (ptr);
}
/*
#include<stdio.h>
int	main(void)
{
	char	a[8] = "ihbdsjAA";
	printf("wynik funkcji to %s", ft_strrchr(a, '1'));	
}*/