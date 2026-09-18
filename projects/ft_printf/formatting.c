/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:04:30 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/20 10:24:24 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int	print_str(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, str, ft_strlen(str));
	return ((int)ft_strlen(str));
}

int	print_num(va_list ap)
{
	int			nbr;
	char		*arr;
	size_t		len;

	nbr = va_arg(ap, int);
	arr = ft_itoa(nbr);
	write(1, arr, ft_strlen(arr));
	len = ft_strlen(arr);
	free(arr);
	return ((int)len);
}

int	print_unsigned(char type, va_list ap)
{
	unsigned int	nbr;

	nbr = va_arg(ap, unsigned int);
	if (type == 'u')
		return (put_unsigned_base(nbr, "0123456789"));
	if (type == 'x')
		return (put_unsigned_base(nbr, "0123456789abcdef"));
	if (type == 'X')
		return (put_unsigned_base(nbr, "0123456789ABCDEF"));
	return (0);
}

int	print_mem(va_list ap)
{
	void				*ptr;
	unsigned long long	mem;

	ptr = va_arg(ap, void *);
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	mem = (unsigned long long)ptr;
	write(1, "0x", 2);
	return (put_ptr_base(mem, "0123456789abcdef") + 2);
}
