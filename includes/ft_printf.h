/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 12:35:39 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/22 14:28:17 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include "../libft/libft.h"

typedef struct 	s_arg
{
	char	*types;
	char	call;
	int		has_space;
	int		has_zero;
	int		has_minus;
	int		has_plus;
	int 	min_width;
	int		has_pound;
	int		printed_chars;
	int		precision;
	int		hh;
	int		h;
	int		l;
	int		ll;
	int		j;
	int		z;
	int		t;
}				t_arg;

void	handle_char(int c, t_arg *args);
void	handle_string(char *str, t_arg *args, int ct);
void	handle_int(intmax_t num, t_arg *args, int ct);
void	handle_double(double num);
void	handle_octal(intmax_t octal, t_arg *args);
void 	handle_hex(unsigned long long n, t_arg *args, int ct);
void	handle_unsigned_int(intmax_t num, t_arg *args, int ct);

intmax_t	atoi_edit(const char *str);
int		strchr_edit(const char *str, int c);
char	*ft_itoa_edit(intmax_t n);
void	replace_zeros(char *str);
int		int_strchr(const char *str, int c);
void	fix_signs(char *str);

#endif
