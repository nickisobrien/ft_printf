/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 22:07:46 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/21 15:37:13 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_unsigned_int(intmax_t num, t_arg *args, int ct)
{
	if (args->has_space) //warning, ' ' is undefined with unsigned
		args->has_space = 0;
	if (num < 0)
		num = 4294967296 + num;
	if (ct == 1)
		handle_int(num, args, 1);
	else if (ct == 2 || ct == 3)
		handle_hex(num, args, ct);
}