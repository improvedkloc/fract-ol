/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init.c                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:40:45 by dklockow          #+#    #+#             */
/*   Updated: 2024/08/28 20:00:42 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 50;
	fractal->sign = 1;
	fractal->focus_x = WIDTH / 2;
	fractal->focus_y = HEIGHT / 2;
	fractal->shift_x = 0;
	fractal->shift_old_x = 0;
	fractal->mv_x = 0;
	fractal->shift_y = 0;
	fractal->shift_old_y = 0;
	fractal->mv_y = 0;
	fractal->zoom = 1.0;
	fractal->range_min_x = -2;
	fractal->range_max_x = 2;
	fractal->range_min_y = 2;
	fractal->range_max_y = -2;
	fractal->is_dragging = 0;
	fractal->click_x = 0;
	fractal->click_y = 0;
}

void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, 17, (1L << 17), close_handler, fractal);
	mlx_hook(fractal->mlx_window, MOUSEMOVE, (1L << 6), move_handler, fractal);
	mlx_hook(fractal->mlx_window, MOUSERELEASE, (1L << 3),
		release_handler, fractal);
	mlx_key_hook(fractal->mlx_window, key_handler, fractal);
	mlx_mouse_hook(fractal->mlx_window, mouse_handler, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		exit(MALLOC_ERROR);
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		exit(MALLOC_ERROR);
	}
	fractal->img.image = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (fractal->img.image == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		exit(MALLOC_ERROR);
	}
	fractal->img.data = mlx_get_data_addr(fractal->img.image, &fractal->img.bpp,
			&fractal->img.size_line, &fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
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
