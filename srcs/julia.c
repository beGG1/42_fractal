/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 05:18:05 by sshabali          #+#    #+#             */
/*   Updated: 2025/02/06 12:33:56 by sshabali         ###   ########.fr       */
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

void put_pixel(t_window *win, int x, int y, int color) {
    if (x >= 0 && x < win->w && y >= 0 && y < win->h) {
        int index = (y * win->size_line) + (x * (win->bpp / 8));
        win->img_data[index] = color & 0xFF;
        win->img_data[index + 1] = (color >> 8) & 0xFF;
        win->img_data[index + 2] = (color >> 16) & 0xFF;
    }
}

void draw_fractal(t_window *win, void (*fractal_func)(t_window *, int, int)) {
    int y = 0;
    while (y < win->h) {
        int x = 0;
        while (x < win->w) {
            fractal_func(win, x, y);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(win->mlx, win->window, win->img, 0, 0);
}

void julia_pixel(t_window *win, int x, int y) {
    double zx = 1.5 * ((x - win->w / 2) / (0.5 * win->w)) / win->zoom + win->move_x;
    double zy = ((y - win->h / 2) / (0.5 * win->h)) / win->zoom + win->move_y;
    double c_re = cX, c_im = cY;
    int iter = 0;
    while (zx * zx + zy * zy < 4.0 && iter < max_iter) {
        double tmp = zx * zx - zy * zy + c_re;
        zy = 2.0 * zx * zy + c_im;
        zx = tmp;
        iter++;
    }
    put_pixel(win, x, y, get_color(iter));
}

void mandelbrot_pixel(t_window *win, int x, int y) {
    double c_re = 1.5 * ((x - win->w / 2) / (0.5 * win->w)) / win->zoom + win->move_x;
    double c_im = ((y - win->h / 2) / (0.5 * win->h)) / win->zoom + win->move_y;
    double zx = 0, zy = 0;
    int iter = 0;
    while (zx * zx + zy * zy < 4.0 && iter < max_iter) {
        double tmp = zx * zx - zy * zy + c_re;
        zy = 2.0 * zx * zy + c_im;
        zx = tmp;
        iter++;
    }
    put_pixel(win, x, y, get_color(iter));
}

void burning_ship_pixel(t_window *win, int x, int y) {
    double c_re = 1.5 * ((x - win->w / 2) / (0.5 * win->w)) / win->zoom + win->move_x;
    double c_im = ((y - win->h / 2) / (0.5 * win->h)) / win->zoom + win->move_y;
    double zx = 0, zy = 0;
    int iter = 0;
    while (zx * zx + zy * zy < 4.0 && iter < max_iter) {
        double tmp = zx * zx - zy * zy + c_re;
        zy = (2.0 * zx * zy < 0) ? -(2.0 * zx * zy) + c_im : (2.0 * zx * zy) + c_im;
        zx = (tmp < 0) ? -tmp : tmp;
        iter++;
    }
    put_pixel(win, x, y, get_color(iter));
}
