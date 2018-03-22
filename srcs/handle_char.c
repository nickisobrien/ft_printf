/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 12:14:54 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/21 20:10:07 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_char(int c, t_arg *args)
{
	char *str;

	if (c == 0)
	{
		str = ft_strnew(0);
		ft_putchar(0);
		args->printed_chars++;
	}
	else
	{
		str = ft_strnew(1);
		str[0] = c;
	}
	handle_string(str, args, 0);
}