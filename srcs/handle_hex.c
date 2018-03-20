/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 21:11:58 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/19 18:37:05 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_hex(long long n, t_arg *args, int var)
{
	char *str;
	long long temp;
	int len;

	//printf("\n|%lld|\n", n);
	len = 1;
	temp = n;
	while (temp /= 16)
		len++;
	str = ft_strnew(len);
	len--;
	if (!n)
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
	if (var == 3)
		ft_strupper(str);
	//might need to change so i can handle 08x
	handle_string(str, args);
}