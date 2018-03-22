/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:14:30 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/22 15:15:11 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	num_handler(intmax_t num, t_arg *args)
{
	if (args->hh && (args->call == 'd' || args->call == 'i'))
		handle_int((char)num, args, 0);
	else if (args->call == 'd' || args->call == 'i')
		handle_int(num, args, 0);
	else if (args->call == 'x')
		handle_unsigned_int(num, args, 2);
	else if (args->call == 'X')
		handle_unsigned_int(num, args, 3);
	else if (args->call == 'o')
		handle_octal(num, args);	
	else if (args->call == 'u' || args->call == 'U')
		handle_unsigned_int(num, args, 1);
}

void	char_handler(int c, t_arg *args)
{
	if (args->call == 'c')
		handle_char(c, args);
	else if (args->call == '%')
		handle_char(37, args);
}

void	str_handler(char *str, t_arg *args)
{
	if (args->call == 's')
		handle_string(str, args, 0);
}