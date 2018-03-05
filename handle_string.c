/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 12:09:41 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/05 13:57:30 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_string(char *str, t_arg args)
{
	int len;

	len = ft_strlen(str);
	if (args.width > 0)
	{
		while (args.width > len)
		{
			ft_putchar(' ');
			args.width--;
		}
	}
	ft_putstr(str);
	if (args.width < 0)
	{		
		args.width *= -1;
		while (args.width > len)
		{
			ft_putchar(' ');
			args.width--;
		}
	}
}