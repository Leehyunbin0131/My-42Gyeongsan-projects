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

int	print_num(int fd, va_list ap)
{
	int			nbr;
	char		*arr;
	size_t		len;

	nbr = va_arg(ap, int);
	arr = ft_itoa(nbr);
	if (!arr)
		return (0);
	write(fd, arr, ft_strlen(arr));
	len = ft_strlen(arr);
	free(arr);
	return ((int)len);
}
