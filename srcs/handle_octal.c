/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 20:26:36 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/23 20:46:44 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_octal(uintmax_t num, t_arg *args)
{
	char *str;
	char *spaces;
	int i;
	int j;
	uintmax_t tmp;

	i = 0;
	tmp = num;
	while (tmp != 0)
	{
		tmp /= 8;
		i++;
	}

	j = 1;
	str = ft_strnew(i);
	i--;
	while (num != 0)
	{
		str[i] = (num % 8) + '0';
		num /= 8;
		j *= 10;
		i--;
	}
	if (ft_countdigits(str) < args->precision)
	{
		spaces = ft_strnew(args->precision - ft_countdigits(str));
		ft_memset(spaces, '0', args->precision - ft_countdigits(str));
		str = ft_strjoin(spaces, str);//need to free numstr/precision? 
	}
	str = add_prefix(str, args, 1, 0);
	if ((int)ft_strlen(str) < args->min_width)
	{
		spaces = ft_strnew(args->min_width - ft_strlen(str));
		ft_memset(spaces, ' ', args->min_width - ft_strlen(str));
		if (args->has_minus)
			str = ft_strjoin(str, spaces);
		else
			str = ft_strjoin(spaces, str);
	}
	if (str[0])
		handle_string(str, args, 1);
	else
	{
		if (args->precision != -1)
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
