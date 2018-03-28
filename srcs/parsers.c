/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:11:21 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/25 14:29:25 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		parse_args(char *str, t_arg *args)
{
	int i;

	i = 0;
	while (str[i] == '+' || str[i] == '-' || str[i] == ' '
		|| str[i] == '0' || str[i] == '#')
	{
		if (str[i] == '+')
			args->has_plus = 1;
		else if (str[i] == '-')
			args->has_minus = 1;
		else if (str[i] == ' ')
			args->has_space = 1;
		else if (str[i] == '0')
			args->has_zero = 1;
		else if (str[i] == '#')
			args->has_pound = 1;
		i++;
	}
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.' && !(args->precision = atoi_edit(&(str[i + 1]))))
		args->precision = -1;
	while (str[i] == '.' || ft_isdigit(str[i]))
		i++;
	return (i);
}

int		parse_flags(char *str, t_arg *args)
{
	int i;

	i = 0;
	while (str[i] == 'h' || str[i] == 'l' || str[i] == 'j'
		|| str[i] == 'z' || str[i] == 't')
	{
		if (str[i] == 'h' && str[i + 1] == 'h')
			args->hh = 1 + (i++ * 0);
		else if (str[i] == 'l' && str[i + 1] == 'l')
			args->ll = 1 + (i++ * 0);
		else if (str[i] == 'h')
			args->h = 1;
		else if (str[i] == 'l')
			args->l = 1;
		else if (str[i] == 'j')
			args->j = 1;
		else if (str[i] == 'z')
			args->z = 1;
		else if (str[i] == 't')
			args->t = 1;
		i++;
	}
	return (i);
}
