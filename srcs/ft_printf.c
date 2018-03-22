/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 16:21:23 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/22 15:06:28 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int 	ft_printf(char *str, ...);

// int 	main(void)
// {
// 	printf("t:%jx|\n", -4294967296);
// 	ft_printf("m:%jx|\n", -4294967296);

// 	printf("t:%x|\n", -42);
// 	ft_printf("m:%x|\n", -42);

// 	printf("t:%lu|\n", -42);
// 	ft_printf("m:%lu|\n", -42);

// 	// printf("t:%hU|\n", 4294967296);
// 	// ft_printf("m:%hU|\n", 4294967296);
// }

void	init_arg(t_arg *arg)
{
	arg->has_zero = 0;
	arg->has_minus = 0;
	arg->has_space = 0;
	arg->min_width = 0;
	arg->has_plus = 0;
	arg->has_pound = 0;
	arg->precision = 0;
	arg->hh = 0;
	arg->ll = 0;
	arg->h = 0;
	arg->l = 0;
	arg->j = 0;
	arg->z = 0;
	arg->t = 0;
	arg->call = 0;
}

void	init_arg_world(t_arg *args)
{
	args->types = ft_strdup("dDioOuUxXsSpCc%%");
}

int		parse_args(char *str, t_arg *args)
{
	int i;

	i = 0;
	while (str[i] == '+' || str[i] == '-' || str[i] == ' ' || str[i] == '0' || str[i] == '#')
	{
		if (str[i] == '+')
			args->has_plus = 1;
		else if (str[i] == '-')
			args->has_minus = 1;
		else if (str[i] == ' ')
			args->has_space = 1;
		else if (str[i] == '0')
			args->has_zero = 1;
		else if (str[i] == '#')
			args->has_pound = 1;
		i++;
	}
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
		if (!(args->precision = labs(atoi_edit(&(str[i + 1])))))
			args->precision = -1;
	while (str[i] == '.' || ft_isdigit(str[i]))
		i++;
	return (i);
}

int		parse_flags(char *str, t_arg *args)
{
	int i;

	i = 0;
	while (str[i] == 'h' || str[i] == 'l' || str[i] == 'j' || str[i] == 'z' || str[i] == 't')
	{
		if (str[i] == 'h' && str[i + 1] == 'h')
			args->hh = 1;
		else if (str[i] == 'l' && str[i + 1] == 'l')
			args->ll = 1;
		else if (str[i] == 'h')
			args->h = 1;
		else if (str[i] == 'l')
			args->ll = 1;
		else if (str[i] == 'j')
			args->j = 1;
		else if (str[i] == 'z')
			args->z = 1;
		else if (str[i] == 't')
			args->t = 1;
		i++;
	}
	return (i);
}

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

int 	ft_printf(char *str, ...)
{
	va_list ap;
	t_arg	args;
	int i;
	int index;


	args.printed_chars = 0;
	va_start(ap, str);
	i = 0;
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
		i++;
		args.min_width = labs(atoi_edit(&str[i])); //can use abs?
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
				else if (args.h)
					num_handler((short)va_arg(ap, int), &args);
				else if (args.hh)
					num_handler((signed char)va_arg(ap, int), &args);
				else if (str[i] == 'u' || str[i] == 'U')
					num_handler(va_arg(ap, unsigned int), &args);
				else
					num_handler(va_arg(ap, int), &args);
			}
			else if (index >= 13)
				char_handler(va_arg(ap, int), &args);
			else
				str_handler(va_arg(ap, char *), &args);
		}
		i++;
	}
	va_end(ap);
	return (args.printed_chars);
}