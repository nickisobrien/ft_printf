/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 12:12:13 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/21 12:52:46 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	replace_zeros(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			str[i] = '0';
		i++;
	}
	fix_signs(str);
}

void	fix_signs(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' && str[0] != ' ')
		{
			str[i] = str[0];
			str[0] = '+';
		}
		else if (str[i] == '-' && str[0] != ' ')
		{
			str[i] = str[0];
			str[0] = '-';
		}
		else if (str[i] == 'x')
		{
			str[i] = str[1];
			str[1] = 'x';
		}
		i++;
	}
}

int		ft_countdigits(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
			i++;
		str++;
	}
	return (i);
}

void	handle_int(intmax_t num, t_arg *args, int ct)
{
	char *numstr;
	char *precision;
	char *spaces;

	if (num || args->precision != -1)
		numstr = ft_itoa_edit(num);
	else
		numstr = ft_strnew(0);
	if (ft_countdigits(numstr) < args->precision)
	{
		precision = ft_strnew(args->precision - ft_countdigits(numstr));
		ft_memset(precision, '0', args->precision - ft_countdigits(numstr));
		numstr = ft_strjoin(precision, numstr);//need to free numstr/precision? 
	}
	if (args->has_pound && ct == 2)//octal call with #
		numstr = ft_strjoin("0", numstr);
	else if (args->has_plus && num >= 0 && ct != 1)//unsigned w//need to free numstr?
		numstr = ft_strjoin("+", numstr);
	else if (args->has_space && num >= 0 && ct != 1)
		numstr = ft_strjoin(" ", numstr);//need to free numstr?

	if ((int)ft_strlen(numstr) < args->min_width)
	{
		spaces = ft_strnew(args->min_width - ft_strlen(numstr));
		ft_memset(spaces, ' ', args->min_width - ft_strlen(numstr));
		if (args->has_minus)
			numstr = ft_strjoin(numstr, spaces);
		else
			numstr = ft_strjoin(spaces, numstr);
	}
	if (args->has_zero && !args->has_minus && !args->precision) //0 flag is ignored with minus flag
		replace_zeros(numstr);
	else
		fix_signs(numstr);
	args->printed_chars += ft_strlen(numstr);
	ft_putstr(numstr);
}




