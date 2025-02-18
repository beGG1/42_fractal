/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 05:18:05 by sshabali          #+#    #+#             */
/*   Updated: 2025/02/18 00:52:54 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int get_color(int iter)
{
	int r;
	int g;
	int b;

	if (iter == max_iter)
		return 0x000000;
	r = (iter * 9) % 256;
	g = (iter * 7) % 256;
	b = (iter * 5) % 256;
	return (r << 16) | (g << 8) | b;
}

void put_pixel(t_window *win, int x, int y, int color)
{
	int index;

	if (x >= 0 && x < win->w && y >= 0 && y < win->h)
	{
		index = (y * win->size_line) + (x * (win->bpp / 8));
		win->img_data[index] = color & 0xFF;
		win->img_data[index + 1] = (color >> 8) & 0xFF;
		win->img_data[index + 2] = (color >> 16) & 0xFF;
	}
}

void draw_fractal(t_window *win, void (*fractal_func)(t_window *, int, int))
{
	int y;
	int x;

	y = 0;
	while (y < win->h)
	{
		x = 0;
		while (x < win->w)
		{
			fractal_func(win, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(win->mlx, win->window, win->img, 0, 0);
}

void julia_pixel(t_window *win, int x, int y)
{
	double	zx;
	double	zy;
	int		iter;
	double	tmp;

	zx = 1.5 * ((x - win->w / 2) / (0.5 * win->w)) / win->zoom + win->move_x;
	zy = ((y - win->h / 2) / (0.5 * win->h)) / win->zoom + win->move_y;
	iter = 0;
	while (zx * zx + zy * zy < 4.0 && iter < max_iter)
	{
		tmp = zx * zx - zy * zy + win->x;
		zy = 2.0 * zx * zy + win->y;
		zx = tmp;
		iter++;
	}
	put_pixel(win, x, y, get_color(iter));
}

void mandelbrot_pixel(t_window *win, int x, int y)
{
	double	zx;
	double	zy;
	int		iter;
	double	tmp;

	zx = 0;
	zy = 0;
	iter = 0;
	while (zx * zx + zy * zy < 4.0 && iter < max_iter)
	{
		tmp = zx * zx - zy * zy + (1.5 * ((x - win->w / 2) / (0.5 * win->w)) / win->zoom + win->move_x);
		zy = 2.0 * zx * zy + (((y - win->h / 2) / (0.5 * win->h)) / win->zoom + win->move_y);
		zx = tmp;
		iter++;
	}
	put_pixel(win, x, y, get_color(iter));
}

void burning_ship_pixel(t_window *win, int x, int y)
{
	double	tmp;
	double	zx;
	double	zy;
	int		iter;

	zx = 0;
	zy = 0;
	iter = 0;
	while (zx * zx + zy * zy < 4.0 && iter < max_iter)
	{
		tmp = zx * zx - zy * zy + (1.5 * ((x - win->w / 2) / (0.5 * win->w)) / win->zoom + win->move_x);
		if (2.0 * zx * zy < 0)
			zy = -(2.0 * zx * zy) + (((y - win->h / 2) / (0.5 * win->h)) / win->zoom + win->move_y);
		else
			zy = (2.0 * zx * zy) + (((y - win->h / 2) / (0.5 * win->h)) / win->zoom + win->move_y);
		if (tmp < 0)
			zx = -tmp;
		else
			zx = tmp;
		iter++;
	}
	put_pixel(win, x, y, get_color(iter));
}
