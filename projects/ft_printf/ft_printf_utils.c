/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:56:58 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/19 17:31:41 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

static int	num_len(long long n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_putnbr(long long n, char *arr, int idx)
{
	if (n >= 10)
		ft_putnbr(n / 10, arr, idx - 1);
	arr[idx] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char		*arr;
	long long	num;
	int			arr_len;

	num = n;
	if (n < 0)
		num = num * -1;
	arr_len = num_len(num);
	if (n < 0)
		arr_len = arr_len + 1;
	arr = (char *)malloc((arr_len + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	arr[arr_len] = '\0';
	ft_putnbr(num, arr, arr_len - 1);
	if (n < 0)
		arr[0] = '-';
	return (arr);
}
