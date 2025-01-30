/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 05:18:05 by sshabali          #+#    #+#             */
/*   Updated: 2025/01/30 09:08:43 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"
# define cX -0.8
# define cY 0.156
# define max_iter 255
# define move_x 0
# define move_y 0
# define zoom 1
# define goldenRatio 1.61803398875

void draw_julia(t_window *win, double c_re, double c_im) {
    for (int y = 0; y < win->h; y++) {
        for (int x = 0; x < win->w; x++) {
            double zx = 1.5 * (x - win->w / 2) / (0.5 * win->w);
            double zy = (y - win->h / 2) / (0.5 * win->h);
            int iter = 0;
            
            while (zx * zx + zy * zy < 4.0 && iter < max_iter) {
                double tmp = zx * zx - zy * zy + c_re;
                zy = 2.0 * zx * zy + c_im;
                zx = tmp;
                iter++;
            }
            
            int color;
            if (iter == max_iter) {
                color = 0x000000;
            } else {
                color = (iter * 255 / max_iter) << 16;
            }
            
            mlx_pixel_put(win->mlx, win->window, x, y, color);
        }
    }
}