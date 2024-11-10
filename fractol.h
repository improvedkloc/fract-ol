/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dklockow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:48:49 by dklockow          #+#    #+#             */
/*   Updated: 2024/08/28 17:13:58 by dklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define WIDTH 800
# define HEIGHT 800
# define MALLOC_ERROR 2
# define EXIT_FAILURE 1
# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or\
\n\t\"./fractol julia <value_1> <value_2>\"\n"
# define COLORMIN 0x000000
# define COLORMAX 0xFFFFFF
# define COLORFRACTAL 0xCCCCCC
# define LEFTCLICK 1
# define RIGHTCLICK 2
# define MIDDLECLICK 3
# define SCROLLUP 4
# define SCROLLDOWN 5
# define MOUSEMOVE 6
# define MOUSERELEASE 5
# define XK_DOWN 65364
# define XK_UP 65362
# define XK_RIGHT 65363
# define XK_LEFT 65361
# define XK_PLUS 65451
# define XK_MINUS 65453
# define XK_ESCAPE 65307

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_img
{
	void	*image;
	char	*data;
	int		bpp;
	int		endian;
	int		size_line;
}				t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	int		is_dragging;
	double	sign;
	int		click_x;
	int		shift_x;
	int		shift_old_x;
	int		mv_x;
	int		click_y;
	int		shift_y;
	int		shift_old_y;
	int		mv_y;
	int		focus_x;
	int		focus_y;
	double	range_min_x;
	double	range_max_x;
	double	range_min_y;
	double	range_max_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractal;

//f_init
void	data_init(t_fractal *fractal);
void	events_init(t_fractal *fractal);
void	fractal_init(t_fractal *fractal);

//f_events
int		key_handler(int keycode, t_fractal *fractal);
int		mouse_handler(int button, int x, int y, t_fractal *fractal);
int		close_handler(t_fractal *fractal);
int		move_handler(int x, int y, t_fractal *fractal);
int		release_handler(int button, int x, int y, t_fractal *fractal);

//f_rend
void	render_pixel(t_fractal *fractal, int x, int y);
void	fractal_render(t_fractal *fractal);

//utils
double	atod(char *str);
double	map(double new_min, double new_max, double old_max, double n);
int		exit_wrong_input(void);
void	mandel_vs_julia(t_point *z, t_point *c, t_fractal *fractal);

#endif