/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:55:05 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/26 16:26:17 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*handle_width(char *str, t_arg *args)
{
	int		dif;
	char	*spaces;
	char	*ptr;

	ptr = str;
	dif = args->min_width - ft_strlen(str);
	if (dif > 0)
	{
		spaces = ft_strnew(dif);
		ft_memset(spaces, ' ', dif);
		if (args->has_minus)
			str = ft_strjoin(str, spaces);
		else
			str = ft_strjoin(spaces, str);
		free(str);//why am i freeing str...
	}
	return (str);
}

void	handle_string(char *str, t_arg *args)
{
	char	*newstr;
	
	if (!str)
		str = "(null)";
	if ((int)ft_strlen(str) > args->precision && args->precision != 0 && args->precision != -1 && ft_tolower(args->call) != 'x')
	{
		newstr = ft_strnew(args->precision);
		ft_strncpy(newstr, str, args->precision);
		str = newstr; //free(str/newstr);
	}
	str = handle_width(str, args);
	if (args->has_zero && !args->has_minus) //0 flag is ignored with minus flag
		replace_zeros(str, args->has_space);
	while (*str)
		add_char(*str++, args);
}