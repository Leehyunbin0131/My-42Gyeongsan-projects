/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:42:31 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/20 10:21:34 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_outout(char type, va_list ap)
{
	if (type == 'c')
		return (print_char(ap));
	if (type == 's')
		return (print_str(ap));
	if (type == 'd' || type == 'i')
		return (print_num(ap));
	if (type == 'u' || type == 'x' || type == 'X')
		return (print_unsigned(type, ap));
	if (type == 'p')
		return (print_mem(ap));
	if (type == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

static int	format_process(const char *format, int *n, va_list ap)
{
	int		count;
	char	type;

	if (format[*n] == '\0')
		return (0);
	if (format[*n] != '%')
	{
		write(1, &format[*n], 1);
		(*n)++;
		return (1);
	}
	if (format[*n + 1] == '\0')
	{
		(*n)++;
		return (0);
	}
	type = format[*n + 1];
	count = 0;
	count = format_outout(type, ap);
	(*n) += 2;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		n;
	int		count;

	count = 0;
	n = 0;
	va_start(ap, format);
	while (format[n] != '\0')
		count += format_process(format, &n, ap);
	va_end(ap);
	return (count);
}
