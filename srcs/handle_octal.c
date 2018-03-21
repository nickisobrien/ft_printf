/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 20:26:36 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/20 22:14:10 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//need to figure out how to handle #?
void	handle_octal(int num, t_arg *args)
{
	int octalNumber;
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
