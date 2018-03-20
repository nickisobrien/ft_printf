/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 22:07:46 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/20 13:35:19 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_unsigned_int(long long num, t_arg *args, int func)
{
	if (!args->l && !args->ll && num == 4294967296)
		num = 0;
	if (args->has_space)
	{
		//warning, ' ' is undefined with unsigned
		args->has_space = 0;
	}
	if (num < 0)
		num = 4294967296 + num;
	if (func == 1)
		handle_int(num, args);
	else if (func == 2 || func == 3)
		handle_hex(num, args, func);
}