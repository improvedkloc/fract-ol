/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:52:09 by dklockow          #+#    #+#             */
/*   Updated: 2024/03/08 19:04:08 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	ft_function(unsigned int i, char *s)
{
	*s = *s + i;
}

#include<stdio.h>

int	main(void)
{
char	input[] = "aaaaaa";
ft_striteri(input, ft_function);
printf("input %s\n", input);
}*/