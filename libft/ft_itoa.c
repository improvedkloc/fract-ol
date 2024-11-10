/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:58:06 by dklockow          #+#    #+#             */
/*   Updated: 2024/03/08 00:35:35 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_number(int number)
{
	int	i;

	i = 0;
	if (number == 0)
		return (1);
	if (number < 0 && number != -2147483648)
	{
		number = number * (-1);
		i++;
	}
	if (number == -2147483648)
		return (11);
	while (number > 0)
	{
		i++;
		number = number / 10;
	}
	return (i);
}

static int	min_int_write(char *str)
{
	str[0] = '-';
	str[1] = '2';
	return (147483648);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = digit_number(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0 && n != -2147483648)
	{
		str[0] = '-';
		n = n * (-1);
	}
	if (n == 0)
		str[0] = '0';
	if (n == -2147483648)
		n = min_int_write(str);
	str[len] = '\0';
	while (n > 0)
	{
		str[--len] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
/*
#include<stdio.h>
int	main(void)
{
	printf("%s", ft_itoa(-214748364));
}*/