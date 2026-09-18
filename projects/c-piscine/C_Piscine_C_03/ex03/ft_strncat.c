/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:44:47 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/02 16:21:34 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	n;
	unsigned int	m;

	n = 0;
	m = 0;
	while (dest[n] != '\0')
	{
		n++;
	}
	while (src[m] != '\0' && m < nb)
	{
		dest[n] = src[m];
		n++;
		m++;
	}
	*(dest + n) = '\0';
	return (dest);
}

#include <stdio.h>
int main() {
   char str1[20] = "Hello, ";
   char str2[] = "World!";

   ft_strncat(str1, str2, 3);
   printf("%s\n", str1); 

   return 0;
}