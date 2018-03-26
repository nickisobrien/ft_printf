/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:55:05 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/26 15:02:09 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_wstring(wchar_t *str, t_arg *args)
{
	int i;
	int len;
	char fill;

	if (!str)
		str = L"(null)";
	if (!args->has_minus)
		len = args->min_width - ft_wstrlen(str);
	else
		len = ft_wstrlen(str) - args->min_width;
	fill = args->has_zero ? '0' : ' ';
	i = 0;
	if (!str)
		str = (L"(null)");//can switch my string handler to this not strdup?
	if (!args->has_minus)
		while (len-- > 0)
			args->buf[args->index++] = fill;
	while (str[i])
		handle_wchar(str[i++], args);
	if (args->has_minus)
		while (len++ < 0)
			args->buf[args->index++] = fill;
}
