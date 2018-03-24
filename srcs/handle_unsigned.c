/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 22:07:46 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/23 18:17:35 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_unsigned_int(intmax_t num, t_arg *args, int ct)
{
	//might want to make a variable uintmax_t number to accept num = (uintmaxt_t)num; and the rest..

	if (args->has_space) //warning, ' ' is undefined with unsigned
		args->has_space = 0;
	if (num < 0)//might be able to get rid of some of these...
	{
		if (args->j || args->call == 'U')
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
		handle_int_string(1, args, ct, ft_utoa_edit(num));
	else if (ct == 2 || ct == 3)
		handle_hex(num, args, ct);
}