/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 12:35:39 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/25 14:48:24 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include "../libft/libft.h"

# define BUFF_SIZE 124

typedef struct 	s_arg
{
	char	buf[BUFF_SIZE];
	int		buff_index;
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
void	handle_string(char *str, t_arg *args);
void	handle_int(intmax_t num, t_arg *args, int ct);
void	handle_int_string(intmax_t num, t_arg *args, int ct, char *numstr);
void	handle_double(double num);
void	handle_octal(uintmax_t octal, t_arg *args);
void 	handle_hex(uintmax_t n, t_arg *args);
void	handle_unsigned_int(intmax_t num, t_arg *args, int ct);

//init
void	init_arg(t_arg *arg);
void	init_arg_world(t_arg *arg);

//mid handlers
void	num_handler(va_list ap, t_arg *args);
void	str_handler(va_list ap, t_arg *args);
void	ptr_handler(va_list ap, t_arg *args);
void	char_handler(va_list ap, t_arg *args);

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
char	*ft_utoa_edit(uintmax_t n);
int		ft_countdigits(char *str);
char	*add_prefix(char *numstr, t_arg *args, int num, int ct);


#endif
