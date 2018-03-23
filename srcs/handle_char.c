/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 12:14:54 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/23 14:13:51 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_char(int c, t_arg *args)
{
	char *str;

	if (c == 0)
	{
		if (args->min_width)
			args->printed_chars += args->min_width;
		else
			args->printed_chars++;
		if (!args->has_minus)
			while (args->min_width-- > 1)
				ft_putchar(' ');
		ft_putchar(0);
		if (args->has_minus)
			while (args->min_width-- > 1)
				ft_putchar(' ');
	}
	else
	{
		str = ft_strnew(1);
		str[0] = c;
		handle_string(str, args, 0);
	}
}