/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 12:14:54 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/24 15:47:55 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_char(int c, t_arg *args)
{
	char *str;
	char filler;

	if (c == 0)
	{
		filler = ' ';
		if (args->has_zero)
			filler = '0';
		if (args->min_width)
			args->printed_chars += args->min_width;
		else
			args->printed_chars++;
		if (!args->has_minus)
			while (args->min_width-- > 1)
				ft_putchar(filler);
		ft_putchar(0);
		if (args->has_minus)
			while (args->min_width-- > 1)
				ft_putchar(filler);
	}
	else
	{
		str = ft_strnew(1);
		str[0] = c;
		handle_string(str, args);
	}
}