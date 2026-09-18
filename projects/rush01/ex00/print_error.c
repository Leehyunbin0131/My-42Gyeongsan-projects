/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:14:50 by ykang             #+#    #+#             */
/*   Updated: 2026/02/01 16:49:12 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_error(int error_code)
{
	if (error_code == -88)
		write (1, "Input condition format error \n", 30);
	else if (error_code == -99)
		write (1, "Invalid input condition error \n", 31);
	return (0);
}
