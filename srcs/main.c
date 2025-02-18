/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:50:31 by sshabali          #+#    #+#             */
/*   Updated: 2025/02/18 03:32:16 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	print_with_error_exit(char *text)
{
	int	err;

	err = ft_printf(text);
	if (err < 0)
		exit(1);
}

void	print_info(void)
{
	print_with_error_exit("Avalible sets:\n");
	print_with_error_exit("1) julia (default values -0.8, 0.156)\n");
	print_with_error_exit("2) mandelbrot\n");
	print_with_error_exit("3) burning_ship\n");
}

int	main(int argc, char **argv)
{
	t_window	*win;

	print_info();
	if (argc >= 2)
	{
		win = malloc(sizeof(t_window));
		init_window(win, argc, argv);
		mlx_key_hook(win->window, key_handler, win);
		mlx_mouse_hook(win->window, mouse_handler, win);
		mlx_hook(win->window, 17, 0, close_hook, win);
		mlx_loop(win->mlx);
	}
	return (0);
}
