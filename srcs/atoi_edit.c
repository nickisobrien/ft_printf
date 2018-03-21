/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 22:08:22 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/21 12:54:14 by nobrien          ###   ########.fr       */
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
	{
		*n *= -1;
		*negative = 1;
	}
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
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	if (negative)
		str[0] = '-';
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
