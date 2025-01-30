/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 06:32:17 by sshabali          #+#    #+#             */
/*   Updated: 2025/01/30 16:19:07 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"


void	init_window(t_window *win, int size_x, int size_y, char *title)
{
	win->mlx = mlx_init();
	if (!win->mlx)
	{
		ft_printf("Failed to connect to X11\n");
		destroy_window(1, win);
	}
	win->window = mlx_new_window(win->mlx, size_x, size_y, title);
	if (!win->window)
	{
		ft_printf("Failed to create window\n");
		destroy_window(1, win);
	}
	win->w = size_x;
	win->h = size_y;
	win->move_x = 0.0;
	win->move_y = 0.0;
	win->zoom = 1.0;
}
