/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:07:20 by sshabali          #+#    #+#             */
/*   Updated: 2025/01/11 19:47:32 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"
# define EVENT_CLOSE_BTN 17
# define KEY_ESC 65307

int	close_ever(int key)
{
	if (key == 65307)
		exit(1);
	return (0);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;

	if (argc == 2)
	{
		mlx = mlx_init();
		if (!mlx)
		{
			ft_printf("Failed to connect to X11\n");
			return (0);
		}
		win = mlx_new_window(mlx, 1000, 1000, "Jopa");
		if (!win)
		{
			ft_printf("Failed to connect to create new window\n");
			return (0);
		}
		mlx_string_put(mlx, win, 400, 400, 123, "Hello, World");
		mlx_key_hook(win, close_ever, NULL);
		mlx_loop(mlx);
	}
	return (0);
}