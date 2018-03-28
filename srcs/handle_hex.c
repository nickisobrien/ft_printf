/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 21:11:58 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/26 19:43:00 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_hex(uintmax_t n, t_arg *args)
{
	char *str;
	char *ptr;

	if (args->precision == -1 && !args->min_width)
		return ;
	if (!n && args->precision != -1)
	{
		str = ft_strnew(1);
		str[0] = '0';
	}
	else
		str = ft_utoa_base(n, 16);
	if (args->has_pound && str[0] != '0')
	{
		ptr = str;
		str = ft_strjoin("0x", str);
		free(ptr);
	}
	if (ft_upper(args->call))
		ft_strupper(str);
	handle_string(str, args);
	free(str);
}
