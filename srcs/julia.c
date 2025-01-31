/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 05:18:05 by sshabali          #+#    #+#             */
/*   Updated: 2025/01/31 14:37:22 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"
# define cX -0.8
# define cY 0.156
# define max_iter 255
# define goldenRatio 1.61803398875

int get_color(int iter) {
    if (iter == max_iter)
        return 0x000000;
    int r = (iter * 9) % 256;
    int g = (iter * 7) % 256;
    int b = (iter * 5) % 256;
    return (r << 16) | (g << 8) | b;
}

void draw_julia(t_window *win, double c_re, double c_im) {
    int y = 0;
    while (y < win->h) {
        int x = 0;
        while (x < win->w) {
            double zx = 1.5 * ((x - win->w / 2) / (0.5 * win->w)) / win->zoom + win->move_x;
            double zy = ((y - win->h / 2) / (0.5 * win->h)) / win->zoom + win->move_y;
            int iter = 0;
            
            while (zx * zx + zy * zy < 4.0 && iter < max_iter) {
                double tmp = zx * zx - zy * zy + c_re;
                zy = 2.0 * zx * zy + c_im;
                zx = tmp;
                iter++;
            }
            
            int color = get_color(iter);
            mlx_pixel_put(win->mlx, win->window, x, y, color);
            x++;
        }
        y++;
    }
}

void draw_mandelbrot(t_window *win) {
    int y = 0;
    while (y < win->h) {
        int x = 0;
        while (x < win->w) {
            double c_re = 1.5 * ((x - win->w / 2) / (0.5 * win->w)) / win->zoom + win->move_x;
            double c_im = ((y - win->h / 2) / (0.5 * win->h)) / win->zoom + win->move_y;
            double zx = 0;
            double zy = 0;
            int iter = 0;
            
            while (zx * zx + zy * zy < 4.0 && iter < max_iter) {
                double tmp = zx * zx - zy * zy + c_re;
                zy = 2.0 * zx * zy + c_im;
                zx = tmp;
                iter++;
            }
            
            int color = get_color(iter);
            mlx_pixel_put(win->mlx, win->window, x, y, color);
            x++;
        }
        y++;
    }
}

void draw_burning_ship(t_window *win) {
    int y = 0;
    while (y < win->h) {
        int x = 0;
        while (x < win->w) {
            double c_re = 1.5 * ((x - win->w / 2) / (0.5 * win->w)) / win->zoom + win->move_x;
            double c_im = ((y - win->h / 2) / (0.5 * win->h)) / win->zoom + win->move_y;
            double zx = 0;
            double zy = 0;
            int iter = 0;
            
            while (zx * zx + zy * zy < 4.0 && iter < max_iter) {
                double tmp = zx * zx - zy * zy + c_re;
                zy = ((2.0 * zx * zy) < 0) ? -(2.0 * zx * zy) + c_im : (2.0 * zx * zy) + c_im;
                zx = (tmp < 0) ? -tmp : tmp;
                iter++;
            }
            
            int color = get_color(iter);
            mlx_pixel_put(win->mlx, win->window, x, y, color);
            x++;
        }
        y++;
    }
}