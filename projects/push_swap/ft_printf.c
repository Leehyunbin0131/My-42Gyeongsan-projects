/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:42:31 by hyunlee           #+#    #+#             */
/*   Updated: 2026/06/17 20:40:13 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_output(int fd, char type, va_list ap)
{
	if (type == 'd')
		return (print_num(fd, ap));
	if (type == '%')
	{
		write(fd, "%", 1);
		return (1);
	}
	return (0);
}

static int	format_process(int fd, const char *format, int *n, va_list ap)
{
	int		count;
	char	type;

	if (format[*n] == '\0')
		return (0);
	if (format[*n] != '%')
	{
		write(fd, &format[*n], 1);
		(*n)++;
		return (1);
	}
	if (format[*n + 1] == '\0')
	{
		(*n)++;
		return (0);
	}
	type = format[*n + 1];
	count = format_output(fd, type, ap);
	(*n) += 2;
	return (count);
}

static int	vprintf_fd(int fd, const char *format, va_list ap)
{
	int	n;
	int	count;

	count = 0;
	n = 0;
	while (format[n] != '\0')
		count += format_process(fd, format, &n, ap);
	return (count);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = vprintf_fd(fd, format, ap);
	va_end(ap);
	return (count);
}
