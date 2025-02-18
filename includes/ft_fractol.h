/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:16:25 by sshabali          #+#    #+#             */
/*   Updated: 2025/02/18 00:53:08 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "./libft/libft.h"
# include <mlx.h>

# define max_iter 255

typedef struct s_window
{
	void *mlx;
    void *window;
    void *img;
    char *img_data;
    int bpp;
    int size_line;
	int endian;
    int w;
    int h;
    double move_x;
    double move_y;
    double zoom;
    char    *title;
    double  x;
    double  y;
} t_window;

//void	init_window(t_window *win, int size_x, int size_y, char *title);
double	atod(const char *str);
void init_window(t_window *win, int argc, char **argv);
void	destroy_window(int exit_code, t_window *win);
int		key_handler(int keycode, t_window *win);
int 	close_hook(t_window *win);

void julia_pixel(t_window *win, int x, int y);
void mandelbrot_pixel(t_window *win, int x, int y);
void burning_ship_pixel(t_window *win, int x, int y);

void draw_fractal(t_window *win, void (*fractal_func)(t_window *, int, int));
#endif