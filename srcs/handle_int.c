/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 12:12:13 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/26 14:58:35 by nobrien          ###   ########.fr       */
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
	int j;
	char tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == 'x')
		{
			j = 0;
			while (str[j])
			{
				if (ft_isdigit(str[j]))
				{
					if (str[i] == 'x')
						j++;
					tmp = str[i];
					str[i] = str[j];
					str[j] = tmp;
					break;
				}
				j++;
			}
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

char	*add_prefix(char *numstr, t_arg *args, int num, int ct)
{
	if (args->has_pound && ft_tolower(args->call) == 'o')//octal call with #
		numstr = ft_strjoin("0", numstr);
	else if (args->has_plus && num >= 0 && ct != 1)//unsigned w//need to free numstr?
		numstr = ft_strjoin("+", numstr);
	else if (args->has_space && num >= 0 && ct != 1)
		numstr = ft_strjoin(" ", numstr);//need to free numstr?
	return (numstr);
}

void	handle_int(intmax_t num, t_arg *args, int ct)
{
	char *numstr;

	if (num || args->precision != -1)
		numstr = ft_itoa_edit(num);
	else
		numstr = ft_strnew(0);
	handle_int_string(num, args, ct, numstr);
}

void	handle_int_string(intmax_t num, t_arg *args, int ct, char *numstr)
{
	char *precision;
	char *spaces;

	if (ft_countdigits(numstr) < args->precision)
	{
		precision = ft_strnew(args->precision - ft_countdigits(numstr));
		ft_memset(precision, '0', args->precision - ft_countdigits(numstr));
		numstr = ft_strjoin(precision, numstr);//need to free numstr/precision? 
	}
	numstr = add_prefix(numstr, args, num, ct);
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
	while (*numstr)
		add_char(*numstr++, args);
}




