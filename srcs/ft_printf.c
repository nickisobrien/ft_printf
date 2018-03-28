/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 16:21:23 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/26 19:41:36 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		add_char(char c, t_arg *args)
{
	if (args->index + sizeof(c) == BUFF_SIZE)
		flush(args);
	args->buf[args->index] = c;
	args->index += sizeof(c);
}

void		flush(t_arg *args)
{
	write(1, args->buf, args->index);
	args->printed_chars += args->index;
	args->index = 0;
}

static int	get_handler(va_list ap, char *str, t_arg *args)
{
	int index;
	int i;

	i = 0;
	if (!*str)
		return (0);
	if ((index = int_strchr(args->types, str[i])) != -1)
	{
		args->call = str[i];
		if (index <= 2)
			num_handler(ap, args);
		else if (index <= 8)
			unum_handler(ap, args);
		else if (index >= 12)
			char_handler(ap, args);
		else if (args->call == 'p')
			handle_ptr(ap, args);
		else if (index >= 9 && index <= 10)
			str_handler(ap, args);
		i++;
	}
	return (i);
}

int			ft_printf(char *str, ...)
{
	va_list	ap;
	t_arg	args;

	va_start(ap, str);
	init_arg_world(&args);
	while (*str)
	{
		if (*str != '%')
		{
			add_char(*str++, &args);
			continue;
		}
		init_arg(&args);
		args.min_width = atoi_edit(++str);
		if (!*str)
			break ;
		str += parse_args(str, &args);
		str += parse_flags(str, &args);
		str += get_handler(ap, str, &args);
	}
	flush(&args);
	va_end(ap);
	return (args.printed_chars);
}
