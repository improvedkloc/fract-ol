/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:52:09 by dklockow          #+#    #+#             */
/*   Updated: 2024/03/08 18:09:02 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ptr;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
char	ft_function(unsigned int i, char c)
{
	return (c + i);
}

#include<stdio.h>

int	main(void)
{
char	*input = "aaaaaa";
char	*result = ft_strmapi(input, ft_function);
printf("input %s\n result: %s\n", input, result);
}*/