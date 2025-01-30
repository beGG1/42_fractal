/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 05:18:05 by sshabali          #+#    #+#             */
/*   Updated: 2025/01/30 16:21:38 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"
# define cX -0.8
# define cY 0.156
# define max_iter 255
# define goldenRatio 1.61803398875

void draw_julia(t_window *win, double c_re, double c_im) {
	mlx_clear_window(win->mlx, win->window);
	int y = 0;
	while (y < win->h) {
		int x = 0;
		while (x < win->w) {
			double zx = 1.5 * (x - win->w / 2) / (0.5 * win->w * win->zoom) + win->move_x;
			double zy = (y - win->h / 2) / (0.5 * win->h * win->zoom) + win->move_y;
			int iter = 0;
			
			while (zx * zx + zy * zy < 4.0 && iter < max_iter) {
				double tmp = zx * zx - zy * zy + c_re;
				zy = 2.0 * zx * zy + c_im;
				zx = tmp;
				iter++;
			}
			
			int color = 0x000000;
			if (iter != max_iter) {
				color = (iter * 255 / max_iter) << 1;
			}
			
			mlx_pixel_put(win->mlx, win->window, x, y, color);
			x++;
		}
		y++;
	}
}