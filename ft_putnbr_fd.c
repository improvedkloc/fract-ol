/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:25:32 by dklockow          #+#    #+#             */
/*   Updated: 2024/03/08 19:35:23 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2", 2 * sizeof(char));
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		write(fd, "-", sizeof(char));
		n = (-1) * n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		c = (n % 10) + '0';
		write(fd, &c, sizeof(char));
	}
	if (n <= 9 && n >= 0)
	{
		c = n + '0';
		write(fd, &c, sizeof(char));
	}
}
/*
int	main(void)
{
	ft_putnbr_fd(-216666, 1);
}*/