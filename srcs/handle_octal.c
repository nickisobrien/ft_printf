/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 20:26:36 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/22 15:51:16 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//need to figure out how to handle #?
void	handle_octal(intmax_t num, t_arg *args)
{
	intmax_t octalNumber;
	int i;

	i = 1;
	octalNumber = 0;
    while (num != 0)
    {
        octalNumber += (num % 8) * i;
        num /= 8;
        i *= 10;
    }
    if (octalNumber || args->precision != -1)
		handle_int(octalNumber, args, 2);
	else
	{
		if (args->has_pound)
		{
			ft_putchar('0');
			args->printed_chars++;
		}
		i = 0;
		while (i < args->min_width)
		{
			ft_putchar(' ');
			i++;
			args->printed_chars++;
		}
	}
}
