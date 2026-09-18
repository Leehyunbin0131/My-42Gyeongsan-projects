/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:44:28 by hyunlee           #+#    #+#             */
/*   Updated: 2026/01/25 13:59:30 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	is_ok_print(char a, char b, char c);
void	ft_print_comb(void);

void	is_ok_print(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a != '7')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	a[3];
	int		nb;
	int		nc;

	a[0] = '0';
	while (a[0] <= '9')
	{
		a[1] = a[0] + 1;
		while (a[1] <= '9')
		{
			a[2] = a[1] + 1;
			while (a[2] <= '9')
			{
				is_ok_print(a[0], a[1], a[2]);
				a[2]++;
			}
			a[1]++;
		}
		a[0]++;
	}
}

int main()
{
	ft_print_comb();
}