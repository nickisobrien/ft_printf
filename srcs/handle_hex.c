/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 21:11:58 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/23 18:13:00 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_hex(uintmax_t n, t_arg *args, int ct)
{
	char *str;
	uintmax_t temp;
	int len;

	len = 1;
	temp = n;
	while (temp /= 16)
		len++;
	str = ft_strnew(len);
	len--;
	if (args->precision == -1 && !len && !args->min_width)
		return ;
	if (!n && args->precision != -1)
		str[0] = '0';
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			str[len] = temp + '0';
		else
			str[len] = temp + 'a' - 10;
		n /= 16;
		len--;
	}
	if (args->has_pound && str[0] != '0')
		str = ft_strjoin("0x", str); //need to free str?
	if (ct == 3)
		ft_strupper(str);
	//might need to change so i can handle 08x
	handle_string(str, args, ct);
}