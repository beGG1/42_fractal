/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 06:27:22 by sshabali          #+#    #+#             */
/*   Updated: 2025/02/06 12:28:44 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"
#include "../includes/keys.h"

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
    draw_fractal(win, mandelbrot_pixel);
    //draw_julia(win, -0.7, 0.27015);
    //draw_burning_ship(win);
	return (0);
}