/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 06:27:22 by sshabali          #+#    #+#             */
/*   Updated: 2025/01/30 06:52:17 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"
#include "../includes/keys.h"

int	key_handler(int keycode, t_window *win)
{
	if (keycode == KEY_ESC)
		destroy_window(0, win);
	return (0);
}