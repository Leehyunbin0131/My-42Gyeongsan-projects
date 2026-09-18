/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:15:40 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/19 17:29:56 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_unsigned_base(unsigned int nbr, char *base_str)
{
	unsigned int	base_len;
	int				count;

	count = 0;
	base_len = ft_strlen(base_str);
	if (nbr >= base_len)
		count = count + put_unsigned_base(nbr / base_len, base_str);
	write(1, &base_str[nbr % base_len], 1);
	count++;
	return (count);
}

int	put_ptr_base(unsigned long long nbr, char *base_str)
{
	unsigned int	base_len;
	int				count;

	count = 0;
	base_len = ft_strlen(base_str);
	if (nbr >= base_len)
		count = count + put_ptr_base(nbr / base_len, base_str);
	write(1, &base_str[nbr % base_len], 1);
	count++;
	return (count);
}
