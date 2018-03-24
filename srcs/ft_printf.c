/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 16:21:23 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/23 19:15:20 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include <limits.h>

int 	ft_printf(char *str, ...)
{
	va_list ap;
	t_arg	args;
	int i;
	int index;

	i = 0;
	args.printed_chars = 0;
	va_start(ap, str);
	init_arg_world(&args);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i++]);
			args.printed_chars++;
			continue;
		}
		init_arg(&args);
		args.min_width = labs(atoi_edit(&str[++i]));
		if (!str[i])
			break;
		i += parse_args(&(str[i]), &args);
		i += parse_flags(&(str[i]), &args);

		if ((index = int_strchr(args.types, str[i])) != -1)
		{
			args.call = str[i];
			if (index <= 8)
			{
				if (args.j || args.ll)
					num_handler(va_arg(ap, intmax_t), &args);
				else if (args.l)
					num_handler(va_arg(ap, long), &args);
				else if (args.z)
					num_handler(va_arg(ap, size_t), &args);
				else if (str[i] == 'U')
					num_handler(va_arg(ap, uintmax_t), &args);
				else if (str[i] == 'u')
					num_handler(va_arg(ap, unsigned int), &args);
				else if (args.h)
					num_handler((short)va_arg(ap, int), &args);
				else if (args.hh)
					num_handler((signed char)va_arg(ap, int), &args);
				else
					num_handler(va_arg(ap, int), &args);
			}
			else if (index >= 13)
				char_handler(va_arg(ap, int), &args);
			else if (args.call == 'p')
				ptr_handler(va_arg(ap, intmax_t), &args);
			else
				str_handler(va_arg(ap, char *), &args);
			i++;
		}
	}
	va_end(ap);
	return (args.printed_chars);
}