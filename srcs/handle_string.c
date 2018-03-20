/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:55:05 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/20 15:00:02 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_string(char *str, t_arg *args, int ct)
{
	char	*spaces;
	char	*newstr;
	int		dif;

	if ((int)ft_strlen(str) > args->precision && args->precision != 0 && !ct)
	{
		newstr = ft_strnew(args->precision);
		ft_strncpy(newstr, str, args->precision);
		//free(str);
		str = newstr;
	}
	dif = args->min_width - ft_strlen(str);
	if (dif > 0)
	{
		spaces = ft_strnew(dif);
		ft_memset(spaces, ' ', dif);
		if (args->has_minus)
			str = ft_strjoin(str, spaces);
		else
			str = ft_strjoin(spaces, str);
	}
	if (args->has_zero && !args->has_minus) //0 flag is ignored with minus flag
		replace_zeros(str);
	args->printed_chars += ft_strlen(str);
	ft_putstr(str);
}