/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 01:44:16 by sshabali          #+#    #+#             */
/*   Updated: 2025/02/18 01:44:44 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	get_color(int iter)
{
	int	r;
	int	g;
	int	b;

	if (iter == MAX_ITER)
		return (0x000000);
	r = (iter * 9) % 256;
	g = (iter * 7) % 256;
	b = (iter * 5) % 256;
	return ((r << 16) | (g << 8) | b);
}

void	put_pixel(t_window *win, int x, int y, int color)
{
	int	index;

	if (x >= 0 && x < win->w && y >= 0 && y < win->h)
	{
		index = (y * win->size_line) + (x * (win->bpp / 8));
		win->img_data[index] = color & 0xFF;
		win->img_data[index + 1] = (color >> 8) & 0xFF;
		win->img_data[index + 2] = (color >> 16) & 0xFF;
	}
}

void	draw_fractal(t_window *win, void (*fractal_func)(t_window *, int, int))
{
	int	y;
	int	x;

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
