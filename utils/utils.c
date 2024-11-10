/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:40:45 by dklockow          #+#    #+#             */
/*   Updated: 2024/08/28 20:00:42 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	atod(char *str)
{
	double	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	while ((*str < 48 || *str > 57) && !(*str == 43 || *str == 45))
		str++;
	while (*str == 43 || *str == 45)
	{
		if (*(str++) == 45)
			sign *= -1;
	}
	while (*str >= 48 && *str <= 57)
		result = result * 10 + (*str++ - 48);
	if (*str == 46)
	{
		str++;
		i = 1;
		while (*str >= 48 && *str <= 57)
			result = result + ((*str++ - 48.0) / (pow(10, i++)));
	}
	return (result * sign);
}

double	map(double new_min, double new_max, double old_max, double n)
{
	return (((n * ((new_max - new_min) / (old_max))) + new_min));
}

int	exit_wrong_input(void)
{
	ft_putstr_fd(ERROR_MESSAGE, 1);
	exit(EXIT_FAILURE);
}

void	mandel_vs_julia(t_point *z, t_point *c, t_fractal *fractal)
{
	c->x = 0;
	c->y = 0;
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = z->x;
		c->y = z->y;
		z->x = fractal->julia_x;
		z->y = fractal->julia_y;
	}
}
