/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 12:12:13 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/05 12:40:27 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	check_neg(char *str)
{
	while (*str)
	{
		if (*str == '-')
			return (1);
		str++;
	}
	return (0);
}

char	*handle_plus(char *str, int is_neg, int has_plus, int has_space)
{
	int i;

	if (!is_neg && (has_plus || has_space) && ft_isdigit(str[0]) && str[0] != '0')
	{
		if (has_space)
			str = ft_strjoin(" ", str);
		else
			str = ft_strjoin("+", str);
		str[ft_strlen(str)-1] = '\0';
	}
	else if (!is_neg && (has_plus || has_space))
	{
		i = 0;
		while (!(ft_isdigit(str[i + 1])))
			i++;
		if (has_space)
			str[i] = ' ';
		else
			str[i] = '+';
	}
	return (str);
}

char	*handle_neg_plus(char *str, int zero_fill, int has_plus, int has_space)
{
	int i;
	int is_neg;
	is_neg = check_neg(str);
	i = 0;
	if (!zero_fill && !has_plus && !has_space && !has_space)
		return str;
	while (is_neg && str[i] && zero_fill)
	{
		if (str[i] == '-')
		{
			if (zero_fill)
				str[i] = '0';
			str[0] = '-';
		}
		i++;
	}
	return (handle_plus(str, is_neg, has_plus, has_space));
}

void	handle_int(int num, t_arg args)
{
	char *str1;
	char *str2;
	int neg_width;

	neg_width = 0;
	str1 = ft_itoa(num);
	if (args.width < 0)
	{
		neg_width = 1;
		args.width *= -1;
	}
	if (ft_strlen(str1) < args.width)
	{
		args.width -= ft_strlen(str1);
		str2 = ft_strnew(args.width);
		if ((strchr_edit(args.prefixes, '0')) && (neg_width = 1))
		{
			ft_memset(str2, '0', args.width);
		}
		else
			ft_memset(str2, ' ', args.width);
		if (!neg_width || (ft_strchr(args.prefixes, '0')))
			str1 = ft_strjoin(str2, str1);
		else
			str1 = ft_strjoin(str1, str2);
	}
	str1 = handle_neg_plus(str1, strchr_edit(args.prefixes, '0'), strchr_edit(args.prefixes, '+'), strchr_edit(args.prefixes, ' '));
	ft_putstr(str1);
}