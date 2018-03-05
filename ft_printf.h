/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 12:35:39 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/05 13:57:59 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include "libft/libft.h"

typedef struct 	s_arg
{
	char	prefixes[5];
	int 	width;
}				t_arg;

void	handle_char(int c);
void	handle_string(char *str, t_arg args);
void	handle_int(int num, t_arg args);
void	handle_double(double num);

int		atoi_edit(const char *str);
int		strchr_edit(const char *str, int c);

#endif
