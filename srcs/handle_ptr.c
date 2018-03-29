/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 22:08:22 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/26 19:43:51 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_ptr(va_list ap, t_arg *args)
{
	void	*ptr;
	char	*str;
	int		i;

	i = 0;
	ptr = va_arg(ap, void *);
	if (ptr == 0)
		str = ft_strdup("0x0");
	else
	{
		str = ft_utoa_base((uintmax_t)ptr, 16);
		str = ft_strjoin("0x", str);
	}
	str = handle_width(str, args);
	while (str[i])
		add_char(str[i++], args);
}
