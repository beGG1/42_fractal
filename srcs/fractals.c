/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 05:18:05 by sshabali          #+#    #+#             */
/*   Updated: 2025/02/18 01:44:59 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	julia_pixel(t_window *win, int x, int y)
{
	double	zx;
	double	zy;
	int		iter;
	double	tmp;

	zx = 1.5 * ((x - win->w / 2) / (0.5 * win->w)) / win->zoom + win->move_x;
	zy = ((y - win->h / 2) / (0.5 * win->h)) / win->zoom + win->move_y;
	iter = 0;
	while (zx * zx + zy * zy < 4.0 && iter < MAX_ITER)
	{
		tmp = zx * zx - zy * zy + win->x;
		zy = 2.0 * zx * zy + win->y;
		zx = tmp;
		iter++;
	}
	put_pixel(win, x, y, get_color(iter));
}

void	mandelbrot_pixel(t_window *win, int x, int y)
{
	double	zx;
	double	zy;
	int		iter;
	double	tmp;

	zx = 0;
	zy = 0;
	iter = 0;
	while (zx * zx + zy * zy < 4.0 && iter < MAX_ITER)
	{
		tmp = zx * zx - zy * zy + (1.5 * ((x - win->w / 2)
					/ (0.5 * win->w)) / win->zoom + win->move_x);
		zy = 2.0 * zx * zy + (((y - win->h / 2) / (0.5 * win->h))
				/ win->zoom + win->move_y);
		zx = tmp;
		iter++;
	}
	put_pixel(win, x, y, get_color(iter));
}

void	burning_ship_pixel(t_window *win, int x, int y)
{
	double	tmp;
	double	zx;
	double	zy;
	int		iter;

	zx = 0;
	zy = 0;
	iter = 0;
	while (zx * zx + zy * zy < 4.0 && iter < MAX_ITER)
	{
		tmp = zx * zx - zy * zy + (1.5 * ((x - win->w / 2)
					/ (0.5 * win->w)) / win->zoom + win->move_x);
		if (2.0 * zx * zy < 0)
			zy = -(2.0 * zx * zy) + (((y - win->h / 2)
						/ (0.5 * win->h)) / win->zoom + win->move_y);
		else
			zy = (2.0 * zx * zy) + (((y - win->h / 2) / (0.5 * win->h))
					/ win->zoom + win->move_y);
		if (tmp < 0)
			zx = -tmp;
		else
			zx = tmp;
		iter++;
	}
	put_pixel(win, x, y, get_color(iter));
}
