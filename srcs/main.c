/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:07:20 by sshabali          #+#    #+#             */
/*   Updated: 2025/01/30 09:09:07 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	main(int argc, char **argv)
{
	t_window *win;

	if (argc == 2)
	{
		init_window(win, 1000, 1000, argv[1]);
		draw_julia(win, -0.7, 0.27015);
		// mlx_string_put(win->mlx, win->window, 400, 400, 123, "Hello, World");
		mlx_key_hook(win->window, key_handler, win);
		mlx_loop(win->mlx);
	}
	return (0);
}