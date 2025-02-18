/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:40:06 by sshabali          #+#    #+#             */
/*   Updated: 2025/02/17 22:56:22 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

double	atod(const char *str)
{
	int	sign;
	int int_part;
	int	frac_part;
	int	divisor;
	
	sign = 1;
	int_part = 1;
	frac_part = 0;
	divisor = 1;
	
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		int_part = int_part * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9') {
		frac_part = frac_part * 10 + (*str - '0');
		divisor *= 10;
		str++;
	}
	return sign * (int_part + (double)frac_part / divisor);
}