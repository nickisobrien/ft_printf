/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nobrien <nobrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 16:21:23 by nobrien           #+#    #+#             */
/*   Updated: 2018/03/05 14:10:15 by nobrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_printf(char *str, ...);

int 	main(void)
{
	ft_printf("  mine:%7s...\n", "test");
	printf("theirs:%7s...\n", "test");
	//printf("%x %x %+20d %i", 33, 033, 33, 033);

}

int 	get_argc(char *str)
{
	int i;
	// need to handle %%
	i = 0;
	while (*str)
	{
		if (*str == '%')
			i++;
		str++;
	}
	return (i);
}

/* sSpdDioOuUxXcC
handle checklist: 
binary,
char,
escape,
float,
hex,
int,
long,
null,
octal,
string,
ptr,
unsigned,
wchar,
wstr
*/

int 	ft_printf(char *str, ...)
{
	va_list ap;
	t_arg	args;
	int i;
	int j;

	va_start(ap, get_argc(str));
	//args = malloc(sizeof(args));
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			i++;
			continue;
		}
		//clear args strings
		args.width = 0;
		ft_memset(args.prefixes, 0, 5);
		i++;
		args.width = atoi_edit(&str[i]);
		j = 0;
		while (str[i] == '+' || str[i] == '-' || str[i] == ' ' || str[i] == '0')
		{
			args.prefixes[j] = str[i];
			i++;
			j++;
		}
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] == 'c')
			handle_char(va_arg(ap, int));
		else if (str[i] == 'd' || str[i] == 'i')
			handle_int(va_arg(ap, int), args);
		else if (str[i] == 's')
			handle_string(va_arg(ap, char *), args);
		//else if (type == 'f') type == '.'
		//	handle_double(va_arg(ap, double));
		else if (str[i] == '%')
			ft_putchar('%');
		i++;
	}
	va_end(ap);
	return (0);
}