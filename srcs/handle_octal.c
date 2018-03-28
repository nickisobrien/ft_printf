/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 20:26:36 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/26 19:43:04 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_octal(uintmax_t num, t_arg *args)
{
	char	*str;
	char	*spaces;
	int		i;

	str = ft_utoa_base(num, 8);
	if (ft_countdigits(str) < args->precision)
	{
		spaces = ft_strnew(args->precision - ft_countdigits(str));
		ft_memset(spaces, '0', args->precision - ft_countdigits(str));
		str = ft_strjoin(spaces, str);
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
	{
		handle_string(str, args);
		free(str);
	}
	else
	{
		if (args->precision != -1)
			add_char('0', args);
		i = 0;
		while (i < args->min_width)
		{
			add_char(' ', args);
			i++;
		}
	}
}
