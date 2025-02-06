/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:50:31 by sshabali          #+#    #+#             */
/*   Updated: 2025/02/06 12:38:12 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_fractol.h"

int	main(int argc, char **argv)
{
	t_window *win;

	win = malloc(sizeof(t_window));
	if (argc == 2)
	{
		//init_window(win, 1000, 1000, argv[1]);
		init_window(win);
		//draw_julia(win, -0.7, 0.27015);
		// mlx_string_put(win->mlx, win->window, 400, 400, 123, "Hello, World");
		draw_fractal(win, mandelbrot_pixel);
		mlx_key_hook(win->window, key_handler, win);
		mlx_loop(win->mlx);
	}
	return (0);
}