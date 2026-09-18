/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 13:05:26 by lhb               #+#    #+#             */
/*   Updated: 2026/05/04 11:50:53 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	if (count != 0 && (count * size) / count != size)
	{
		return (NULL);
	}
	arr = malloc(count * size);
	if (arr == NULL)
	{
		return (NULL);
	}
	ft_bzero(arr, count * size);
	return (arr);
}
