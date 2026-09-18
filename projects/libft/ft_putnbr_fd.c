/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:31:31 by hyunlee           #+#    #+#             */
/*   Updated: 2026/05/04 11:50:44 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	*arr;

	i = 0;
	arr = ft_itoa(n);
	while (arr[i] != '\0')
	{
		write(fd, &arr[i], 1);
		i++;
	}
	free(arr);
}
