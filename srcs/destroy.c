/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 06:42:48 by sshabali          #+#    #+#             */
/*   Updated: 2025/02/17 21:31:25 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	destroy_window(int exit_code, t_window *win)
{
	if (win->window && win->mlx)
		mlx_destroy_window(win->mlx, win->window);
	if (win->mlx)
	{
		mlx_loop_end(win->mlx);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	if (win)
		free(win);
	exit(exit_code);
}