/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:14:30 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/26 19:42:26 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	num_handler(va_list ap, t_arg *args)
{
	if (ft_tolower(args->call) == 'd' || ft_tolower(args->call) == 'i')
	{
		if (args->l || ft_upper(args->call))
			handle_int(va_arg(ap, long), args, 0);
		else if (args->ll)
			handle_int(va_arg(ap, long long), args, 0);
		else if (args->j)
			handle_int(va_arg(ap, uintmax_t), args, 0);
		else if (args->h)
			handle_int((short)va_arg(ap, int), args, 0);
		else if (args->hh)
			handle_int((char)va_arg(ap, int), args, 0);
		else if (args->z)
			handle_int(va_arg(ap, size_t), args, 0);
		else
			handle_int(va_arg(ap, int), args, 0);
	}
}

void	unum_handler(va_list ap, t_arg *args)
{
	uintmax_t unum;

	if (ft_tolower(args->call) == 'u' || ft_tolower(args->call) == 'o' || ft_tolower(args->call) == 'x')
	{
		if (args->has_space || args->has_plus) //warning, ' ' is undefined with unsigned
		{
			args->has_plus = 0;
			args->has_space = 0;
		}
		if (args->l || (ft_upper(args->call) && args->call != 'X'))
			unum = va_arg(ap, unsigned long);
		else if (args->ll)
			unum = va_arg(ap, unsigned long long);
		else if (args->j)
			unum = va_arg(ap, uintmax_t);
		else if (args->h)
			unum = (unsigned short)va_arg(ap, int);
		else if (args->hh)
			unum = (unsigned char)va_arg(ap, int);
		else if (args->z)
			unum = va_arg(ap, size_t);
		else
			unum = va_arg(ap, unsigned int);
	}
	if (ft_tolower(args->call) == 'o')
		handle_octal(unum, args);
	else if (ft_tolower(args->call) == 'x')
		handle_hex(unum, args);
	else if (args->call == 'u' || args->call == 'U')
	{
		if (args->precision == -1)
			handle_int_string(1, args, 1, ft_strnew(0));
		else
			handle_int_string(1, args, 1, ft_utoa_edit(unum));
	}
}

void	char_handler(va_list ap, t_arg *args)
{
	if (args->call == 'C' || (args->l && args->call == 'c'))
		handle_wchar(va_arg(ap, wchar_t), args);
	else if (args->call == 'c')
		handle_char((char)va_arg(ap, int), args);
	else if (args->call == '%')
		handle_char(37, args);
}

void	str_handler(va_list ap, t_arg *args)
{
	if (args->call == 'S' || (args->l && args->call == 's'))
		handle_wstring(va_arg(ap, wchar_t *), args);
	else if (args->call == 's')
		handle_string(va_arg(ap, char *), args);

}

void	ptr_handler(va_list ap, t_arg *args)
{
	void *ptr;
	char *str;

	ptr = va_arg(ap, void *);
	if (ptr == 0)
	{
		add_char('0', args);
		add_char('x', args);
		add_char('0', args);
	}
	else
	{
		add_char('0', args);
		add_char('x', args);
		str = utoa_base((uintmax_t)ptr, 16);
		while (*str)
			add_char(*str++, args);
	}
}






