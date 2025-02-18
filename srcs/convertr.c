/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshabali <sshabali@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:40:06 by sshabali          #+#    #+#             */
/*   Updated: 2025/02/18 02:40:49 by sshabali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	skip_whitespace(const char **str)
{
	while ((**str <= 13 && **str >= 9) || **str == 32)
		(*str)++;
	return (1);
}

int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

int	parse_int(const char **str)
{
	int	result;

	result = 0;
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10 + (**str - '0');
		(*str)++;
	}
	return (result);
}

double	parse_fraction(const char **str)
{
	double	frac_part;
	double	divisor;

	frac_part = 0.0;
	divisor = 1.0;
	if (**str == '.')
	{
		(*str)++;
		while (**str >= '0' && **str <= '9')
		{
			frac_part = frac_part * 10 + (**str - '0');
			divisor *= 10;
			(*str)++;
		}
	}
	return (frac_part / divisor);
}

double	atod(const char *str)
{
	int		sign;
	int		int_part;
	double	frac_part;

	skip_whitespace(&str);
	sign = get_sign(&str);
	int_part = parse_int(&str);
	frac_part = parse_fraction(&str);
	return (sign * (int_part + frac_part));
}
