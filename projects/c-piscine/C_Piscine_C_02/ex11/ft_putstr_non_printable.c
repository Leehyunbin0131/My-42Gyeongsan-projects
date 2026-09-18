/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:42:13 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/02 14:39:32 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str);
void	change(unsigned char s);
char	hex(unsigned char c);

char	hex(unsigned char c)
{
	if (c < 10)
	{
		c = c + '0';
	}
	else
	{
		c = (c - 10) + 'a';
	}
	return (c);
}

void	change(unsigned char s)
{
	unsigned char	a;
	unsigned char	b;

	a = s / 16;
	b = s % 16;
	a = hex(a);
	b = hex(b);
	write(1, "\\", 1);
	write(1, &a, 1);
	write(1, &b, 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if ((unsigned char)*str < 32 || (unsigned char)*str > 126)
		{
			change((unsigned char) *str);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
}

#include <stdio.h>
int main()
{
	char src1[] = "Hello\nHow are you?";
	ft_putstr_non_printable(src1);
	write(1,"\n",1);
	char src2[] = "H\rello How are you?";
	ft_putstr_non_printable(src2);
	write(1,"\n",1);
	char src3[] = "Hello How ar\te you?";
	ft_putstr_non_printable(src3);
	write(1,"\n",1);
}