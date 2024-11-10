/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_rend.c                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:40:45 by dklockow          #+#    #+#             */
/*   Updated: 2024/08/28 20:00:42 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	render_pixel(t_fractal *fractal, int x, int y)
{
	t_point	z;
	t_point	c;
	double	tmp;
	int		i;

	i = -1;
	z.x = map(fractal->range_min_x, fractal->range_max_x, WIDTH,
			x - fractal->shift_x - fractal->mv_x) * fractal->zoom;
	z.y = map(fractal->range_min_y, fractal->range_max_y, HEIGHT,
			y - fractal->shift_y - fractal->mv_y) * fractal->zoom;
	mandel_vs_julia(&z, &c, fractal);
	while (++i < fractal->iterations_definition
		&& ((c.x * c.x + c.y * c.y) < fractal->escape_value))
	{
		tmp = c.x;
		c.x = (c.x * c.x - c.y * c.y) + z.x;
		c.y = (2 * tmp * c.y) + z.y;
	}
	*(unsigned int *)(fractal->img.data + ((x * fractal->img.bpp / 8)
				+ (y * fractal->img.size_line)))
		= (int)map(COLORMIN, COLORMAX, fractal->iterations_definition, i);
	if (i == fractal->iterations_definition)
		*(unsigned int *)(fractal->img.data + ((x * fractal->img.bpp / 8)
					+ (y * fractal->img.size_line))) = (int)COLORFRACTAL;
}

void	fractal_render(t_fractal *fractal)
{
	int		i;
	int		j;
	double	tmp;

	tmp = fractal->range_min_x;
	fractal->range_min_x += fractal->sign * map(fractal->range_min_x,
			fractal->range_max_x, WIDTH,
			fractal->focus_x - fractal->shift_x - fractal->mv_x);
	fractal->range_max_x += fractal->sign * map(tmp, fractal->range_max_x,
			WIDTH, fractal->focus_x - fractal->shift_x - fractal->mv_x);
	tmp = fractal->range_min_y;
	fractal->range_min_y += fractal->sign * map(fractal->range_min_y,
			fractal->range_max_y, HEIGHT,
			fractal->focus_y - fractal->shift_y - fractal->mv_y);
	fractal->range_max_y += fractal->sign * map(tmp, fractal->range_max_y,
			HEIGHT, fractal->focus_y - fractal->shift_y - fractal->mv_y);
	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
			render_pixel(fractal, i, j);
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.image, 0, 0);
}
/* int	f(int button, int data)
{
	printf("ale ktos \n");
	if (button == Button1)
        printf("Left mouse button pressed at %i\n", data);
	write(1, "ale", 3);
	return 1;
}

int	f1(int keysym, int data)
{
	printf("ale ktos \n");
	if (keysym == XK_1)
        printf("Left mouse button pressed at %i\n", data);
	write(1, "ale", 3);
	return 1;
} */