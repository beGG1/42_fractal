/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:16:25 by sshabali          #+#    #+#             */
/*   Updated: 2025/01/30 16:18:50 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "./libft/libft.h"
# include "./minilibx/mlx.h"

typedef struct s_window
{
	void	*mlx;
	void	*window;
	int		w;
	int		h;
	double		move_x;
	double		move_y;
	double		zoom;
	
} t_window;

void	init_window(t_window *win, int size_x, int size_y, char *title);
void	destroy_window(int exit_code, t_window *win);
int		key_handler(int keycode, t_window *win);

void draw_julia(t_window *win, double c_re, double c_im);
#endif