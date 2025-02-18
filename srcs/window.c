/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 06:32:17 by sshabali          #+#    #+#             */
/*   Updated: 2025/02/18 02:23:31 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	check_input(t_window *win, int argc, char **argv)
{
	win->title = argv[1];
	if (ft_strncmp(argv[1], "julia", 25) == 0)
	{
		win->x = -0.8;
		win->y = 0.156;
		if (argc > 4)
			destroy_window(0, win);
		if (argc >= 3)
			win->x = atod(argv[2]);
		if (argc == 4)
			win->y = atod(argv[3]);
		return ;
	}
	if (ft_strncmp(argv[1], "mandelbrot", 25) == 0 || \
		ft_strncmp(argv[1], "burning_ship", 25) == 0)
	{
		if (argc > 2)
			destroy_window(0, win);
		win->x = 0.0;
		win->y = 0.0;
		return ;
	}
	destroy_window(0, win);
}

void	init_window(t_window *win, int argc, char **argv)
{
	win->w = 800;
	win->h = 600;
	win->move_x = 0;
	win->move_y = 0;
	win->zoom = 1;
	check_input(win, argc, argv);
	win->mlx = mlx_init();
	win->window = mlx_new_window(win->mlx, win->w, win->h, argv[1]);
	win->img = mlx_new_image(win->mlx, win->w, win->h);
	win->img_data = mlx_get_data_addr(win->img, &win->bpp,
			&win->size_line, &win->endian);
}
