/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 22:07:46 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/22 14:53:35 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_unsigned_int(intmax_t num, t_arg *args, int ct)
{
	if (args->has_space) //warning, ' ' is undefined with unsigned
		args->has_space = 0;
	if (num < 0)
	{
		if (args->j)
			num = (uintmax_t)num;
		else if (args->ll)
			num = (unsigned long long)num;
		else if (args->l)
			num = (unsigned long)num;
		else if (args->h)
			num = (unsigned short)num;
		else if (args->hh)
			num = (unsigned char)num;
		else
			num = (unsigned int)num;
	}
	if (ct == 1)
		handle_int(num, args, ct);
	else if (ct == 2 || ct == 3)
		handle_hex(num, args, ct);
}