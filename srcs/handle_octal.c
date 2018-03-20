/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 20:26:36 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/19 10:27:01 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//need to figure out how to handle #?
void	handle_octal(int num, t_arg *args)
{
	int octalNumber;
	int i;

	i = 1;
	octalNumber = 0;
    while (num != 0)
    {
        octalNumber += (num % 8) * i;
        num /= 8;
        i *= 10;
    }
	handle_int(octalNumber, args);
}
