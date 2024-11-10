/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_events.c                                            :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:40:45 by dklockow          #+#    #+#             */
/*   Updated: 2024/08/28 20:00:42 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <X11/keysymdef.h>

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == XK_RIGHT)
		fractal->mv_x += 10;
	if (keycode == XK_LEFT)
		fractal->mv_x -= 10;
	if (keycode == XK_UP)
		fractal->mv_y -= 10;
	if (keycode == XK_DOWN)
		fractal->mv_y += 10;
	if (keycode == XK_PLUS)
		fractal->iterations_definition += 5;
	if (keycode == XK_MINUS)
		fractal->iterations_definition -= 5;
	if (keycode == XK_ESCAPE)
	{
		mlx_destroy_image(fractal->mlx_connection, fractal->img.image);
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		exit (0);
	}
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == SCROLLUP)
	{
		fractal->zoom *= 0.5;
		fractal->iterations_definition *= 1.0;
		fractal->sign = 1;
		fractal->focus_x = x;
		fractal->focus_y = y;
	}
	if (button == SCROLLDOWN)
	{
		fractal->zoom *= 2;
		fractal->iterations_definition /= 1.0;
		fractal->sign = -0.5;
		fractal->focus_x = x;
		fractal->focus_y = y;
	}
	if (button == LEFTCLICK)
	{
		fractal->is_dragging = 1;
		fractal->click_x = x;
		fractal->click_y = y;
	}
	fractal_render(fractal);
	return (0);
}

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.image);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(0);
}

int	move_handler(int x, int y, t_fractal *fractal)
{
	if (fractal->is_dragging == 1)
	{
		fractal->shift_x = fractal->shift_old_x + x - fractal->click_x;
		fractal->shift_y = fractal->shift_old_y + y - fractal->click_y;
		fractal_render(fractal);
	}
	return (0);
}

int	release_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == LEFTCLICK)
	{
		fractal->is_dragging = 0 * x * y;
		fractal->shift_old_x = fractal->shift_x;
		fractal->shift_old_y = fractal->shift_y;
	}
	if (button == SCROLLUP || button == SCROLLDOWN)
		fractal->sign = 0;
	return (0);
}
/* 	void	*mlx_connection;
	void	*mlx_window;
	int		data;

	data = 1;
		mlx_key_hook(mlx_window, f1, &data);
	mlx_hook(mlx_window, ButtonPress, ButtonPressMask, f, &data);
	mlx_loop(mlx_connection);
	mlx_destroy_window(mlx_connection, mlx_window);
	mlx_destroy_display(mlx_connection);
	free(mlx_connection);
		mlx_connection = mlx_init();
	if (mlx_connection == NULL)
		return MALLOC_ERROR;
	mlx_window = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "window 1");
	if (mlx_window == NULL)
	{
		mlx_destroy_display(mlx_connection);
		free(mlx_connection);
		return MALLOC_ERROR;
	}
	
} */
