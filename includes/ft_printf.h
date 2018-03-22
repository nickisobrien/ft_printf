/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 12:35:39 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/22 15:21:26 by nobrien          ###   ########.fr       */
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

//handlers
void	handle_char(int c, t_arg *args);
void	handle_string(char *str, t_arg *args, int ct);
void	handle_int(intmax_t num, t_arg *args, int ct);
void	handle_double(double num);
void	handle_octal(intmax_t octal, t_arg *args);
void 	handle_hex(unsigned long long n, t_arg *args, int ct);
void	handle_unsigned_int(intmax_t num, t_arg *args, int ct);

//init
void	init_arg(t_arg *arg);
void	init_arg_world(t_arg *arg);

//mid handlers
void	num_handler(intmax_t num, t_arg *args);
void	char_handler(int c, t_arg *args);
void	str_handler(char *str, t_arg *args);

//main
int 	ft_printf(char *str, ...);

//parsers
int		parse_args(char *str, t_arg *args);
int		parse_flags(char *str, t_arg *args);

//helpers
intmax_t	atoi_edit(const char *str);
int		strchr_edit(const char *str, int c);
char	*ft_itoa_edit(intmax_t n);
void	replace_zeros(char *str);
int		int_strchr(const char *str, int c);
void	fix_signs(char *str);

#endif
