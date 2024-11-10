/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:34:56 by dklockow          #+#    #+#             */
/*   Updated: 2024/08/07 14:52:53 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 2 || argc == 4)
	{
		if (((argc == 2) && !ft_strncmp(argv[1], "mandelbrot", 10))
			|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
		{
			fractal.name = argv[1];
			if (!ft_strncmp(fractal.name, "julia", 5))
			{
				if (!(argc == 4))
					exit_wrong_input();
				else
				{
					fractal.julia_x = atod(argv[2]);
					fractal.julia_y = atod(argv[3]);
				}
			}
			fractal_init(&fractal);
			fractal_render(&fractal);
			mlx_loop(fractal.mlx_connection);
		}
	}
	else
		exit_wrong_input();
}
