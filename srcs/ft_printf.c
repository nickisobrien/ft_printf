/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 16:21:23 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/20 16:10:19 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int 	ft_printf(char *str, ...);

// int 	main(void)
// {
// 	// ft_printf("@m moulitest:%#.x %#.0x<\n", 0, 0);
// 	// ft_printf("@m moulitest:%.x %.0x<\n", 0, 0);
// 	// ft_printf("@m moulitest:%5.x %5.0x<\n", 0, 0);
// 	// ft_printf("@t moulitest:%#.x %#.0x<\n", 0, 0);
// 	// ft_printf("@t moulitest:%.x %.0x<\n", 0, 0);
// 	// ft_printf("@t moulitest:%5.x %5.0x<\n", 0, 0);

// 	// ft_printf("  mine:%x\n", 4294967296);
// 	// printf("theirs:%x\n", 4294967296);

// 	// ft_printf("m:@moulitest: >%c<\n", 0);
// 	// printf("t:@moulitest: >%c<\n", 0);

// 	ft_printf("m:%+u\n", 4294967295);
// 	printf("t:%+u\n", 4294967295);
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
}

void	init_arg_world(t_arg *args)
{
	args->types = ft_strdup("sSpdDioOuUxXcC");
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
		args->precision = abs(atoi_edit(&(str[i + 1])));
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

int 	ft_printf(char *str, ...)
{
	va_list ap;
	t_arg	args;
	int i;
	//int index;

	args.printed_chars = 0;
	va_start(ap, str);
	i = 0;
	init_arg_world(&args);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			args.printed_chars++;
			i++;
			continue;
		}
		init_arg(&args);
		i++;
		args.min_width = abs(atoi_edit(&str[i])); //can use abs?
		i += parse_args(&(str[i]), &args);
		i += parse_flags(&(str[i]), &args);
		
		// if ((index = ft_strchr(args->types, str[i])) != -1)
		// {

		// }

		if (str[i] == 'c')
			handle_char(va_arg(ap, int), &args);
		else if (str[i] == 'd' || str[i] == 'i')
			handle_int(va_arg(ap, int), &args, 0);
		else if (str[i] == 's')
			handle_string(va_arg(ap, char *), &args, 0);
		else if (str[i] == '%')
			handle_char(37, &args);
		else if (str[i] == 'o')
			handle_octal(va_arg(ap, int), &args);
		else if (str[i] == 'x')
			handle_unsigned_int(va_arg(ap, long long), &args, 2);
		else if (str[i] == 'X')
			handle_unsigned_int(va_arg(ap, long long), &args, 3);
		else if (str[i] == 'u' || str[i] == 'U')
			handle_unsigned_int(va_arg(ap, long long), &args, 1);
		i++;
	}
	va_end(ap);
	return (args.printed_chars);
}