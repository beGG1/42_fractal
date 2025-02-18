/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 06:27:22 by sshabali          #+#    #+#             */
/*   Updated: 2025/02/18 00:50:13 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"
#include "../includes/keys.h"

void	fractal_selector(t_window *win)
{
	if (ft_strncmp(win->title, "julia", 25) == 0)
		draw_fractal(win, julia_pixel);
	if (ft_strncmp(win->title, "mandelbrot", 25) == 0)
		draw_fractal(win, mandelbrot_pixel);
	if (ft_strncmp(win->title, "burning_ship", 25) == 0)
		draw_fractal(win, burning_ship_pixel);
}

int	key_handler(int keycode, t_window *win)
{
	if (keycode == KEY_ESC)
		destroy_window(0, win);
	if (keycode == KEY_LEFT)
		win->move_x -= 0.1 / win->zoom;
	if (keycode == KEY_RIGHT)
		win->move_x += 0.1 / win->zoom;
	if (keycode == KEY_UP)
		win->move_y -= 0.1 / win->zoom;
	if (keycode == KEY_DOWN)
		win->move_y += 0.1 / win->zoom;
	if (keycode == KEY_ONE)
		win->zoom *= 1.1;
	if (keycode == KEY_TWO)
		win->zoom /= 1.1;
	fractal_selector(win);
	return (0);
}

int	close_hook(t_window *win)
{
	destroy_window(0, win);
	return (0);
}