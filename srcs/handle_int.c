/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 12:12:13 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/26 17:17:59 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	char *ptr;

	if (ft_countdigits(numstr) < args->precision)
	{
		precision = ft_strnew(args->precision - ft_countdigits(numstr));
		ft_memset(precision, '0', args->precision - ft_countdigits(numstr));
		ptr = numstr;
		numstr = ft_strjoin(precision, numstr);
		ft_strdel(&ptr);
		ft_strdel(&precision);
	}
	numstr = add_prefix(numstr, args, num, ct);
	if ((int)ft_strlen(numstr) < args->min_width)
	{
		ptr = numstr;
		spaces = ft_strnew(args->min_width - ft_strlen(numstr));
		ft_memset(spaces, ' ', args->min_width - ft_strlen(numstr));
		if (args->has_minus)
			numstr = ft_strjoin(numstr, spaces);
		else
			numstr = ft_strjoin(spaces, numstr);
		ft_strdel(&spaces);
		ft_strdel(&ptr);
	}
	if (args->has_zero && !args->has_minus && !args->precision)
		replace_zeros(numstr, args->has_space);
	else
		fix_signs(numstr);
	ptr = numstr;
	while (*numstr)
		add_char(*numstr++, args);
	ft_strdel(&ptr);
}
