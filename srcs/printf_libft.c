/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 22:08:22 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/26 19:43:51 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	atoi_edit(const char *str)
{
	int i;
	intmax_t atoi;
	int neg;

	i = 0;
	neg = 0;
	atoi = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+' || str[i] == ' ' || str[i] == '0' || str[i] == '#')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= '0') && (str[i] <= '9'))
	{
		atoi *= 10;
		atoi += str[i] - '0';
		i++;
	}
	if (neg)
		return (-atoi);
	return (atoi);
}

int		strchr_edit(const char *str, int c)
{
	char *ptr;

	ptr = (char *)str;
	while (*ptr != c)
	{
		if (*ptr == '\0')
			return (0);
		ptr++;
	}
	return (1);
}

static void	neg(intmax_t *n, int *negative)
{
	if (*n < 0)
		*negative = 1;
}

char		*ft_itoa_edit(intmax_t n)
{
	int			i;
	char		*str;
	intmax_t	tmp;
	int			negative;

	i = 2;
	negative = 0;
	tmp = n;
	neg(&n, &negative);
	while (tmp /= 10)
		i++;
	i += negative;
	if (!(str = malloc(i)))
		return (NULL);
	str[--i] = '\0';
	while (i--)
	{
		str[i] = labs((n % 10)) + '0';
		n /= 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

char		*ft_utoa_edit(uintmax_t n)
{
	int			i;
	char		*str;
	uintmax_t	tmp;

	i = 2;
	tmp = n;
	while (tmp /= 10)
		i++;
	if (!(str = malloc(i)))
		return (NULL);
	str[--i] = '\0';
	while (i--)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int		int_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

int		ft_wstrlen(wchar_t *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		str++;
	}
	return (i);
}

wchar_t	*ft_wstrnew(size_t size)
{
	return ((wchar_t *)ft_memalloc(size + 1));
}

char	*utoa_base(uintmax_t n, int base)
{
	char *str;
	uintmax_t temp;
	int len;

	len = 1;
	temp = n;
	while (temp /= base)
		len++;
	str = ft_strnew(len);
	len--;
	while (n != 0)
	{
		temp = n % base;
		if (temp < 10)
			str[len] = temp + '0';
		else
			str[len] = temp + 'a' - 10;
		n /= base;
		len--;
	}
	return (str);
}

void	replace_zeros(char *str, int has_space)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && (i || !has_space))
			str[i] = '0';
		i++;
	}
	fix_signs(str);
}

void	fix_signs(char *str)
{
	int i;
	int j;
	char tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == 'x')
		{
			j = 0;
			while (str[j])
			{
				if (ft_isdigit(str[j]))
				{
					if (str[i] == 'x')
						j++;
					tmp = str[i];
					str[i] = str[j];
					str[j] = tmp;
					break;
				}
				j++;
			}
		}
		i++;
	}
}

int		ft_countdigits(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
			i++;
		str++;
	}
	return (i);
}

char	*add_prefix(char *numstr, t_arg *args, int num, int ct)
{
	char *ptr;

	ptr = numstr;
	if (args->has_pound && ft_tolower(args->call) == 'o')//octal call with #
		numstr = ft_strjoin("0", numstr);
	else if (args->has_plus && num >= 0 && ct != 1)//unsigned w//need to free numstr?
		numstr = ft_strjoin("+", numstr);
	else if (args->has_space && num >= 0 && ct != 1)
		numstr = ft_strjoin(" ", numstr);
	else
		numstr = ft_strdup(numstr);
	ft_strdel(&ptr);
	return (numstr);
}
