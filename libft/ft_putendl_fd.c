/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:25:32 by dklockow          #+#    #+#             */
/*   Updated: 2024/03/08 19:44:33 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = ft_strlen(s);
	write(fd, s, sizeof(char) * i);
	write(fd, "\n", sizeof(char));
}
/*
int	main(void)
{
	ft_putendl_fd("ale jaja", 1);
}*/