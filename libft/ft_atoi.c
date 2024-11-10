/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:58:06 by dklockow          #+#    #+#             */
/*   Updated: 2024/03/06 18:47:32 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		sign;
	int		number;

	sign = 1;
	number = 0;
	str = (char *)nptr;
	if (*str == '\0')
		return (0);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = (-1) * sign;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * sign);
}
/*
#include<stdio.h>
int	main(void)
{
	printf("%i", ft_atoi("       ++++--2147ab483645"));
}*/
