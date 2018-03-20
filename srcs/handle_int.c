/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 12:12:13 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/19 18:43:36 by nobrien          ###   ########.fr       */
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
		else if (str[i] == '+')
		{
			str[i] = '0';
			str[0] = '+';
		}
		else if (str[i] == '-')
		{
			str[i] = '0';
			str[0] = '-';
		}
		else if (str[i] == 'x')
		{
			str[1] = 'x';
			str[i] = '0';
		}
		i++;
	}
}

void	handle_int(long long num, t_arg *args)
{
	char *numstr;
	char *precision;
	char *spaces;

	numstr = ft_itoa_edit(num);
	if ((int)ft_strlen(numstr) < args->precision)
	{
		precision = ft_strnew(args->precision - ft_strlen(numstr));
		ft_memset(precision, '0', args->precision - ft_strlen(numstr));
		numstr = ft_strjoin(precision, numstr);//need to free numstr/precision? 
	}
	if (args->has_plus && num >= 0)//need to free numstr?
		numstr = ft_strjoin("+", numstr);
	else if (args->has_space && num >= 0)
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
	if (args->has_zero && !args->has_minus) //0 flag is ignored with minus flag
		replace_zeros(numstr);
	args->printed_chars += ft_strlen(numstr);
	ft_putstr(numstr);
}




