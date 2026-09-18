/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:28:12 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/02 16:27:29 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dlen;
	unsigned int	slen;
	unsigned int	i;

	dlen = 0;
	slen = 0;
	i = 0;
	while (dest[dlen])
		dlen++;
	while (src[slen])
		slen++;
	if (size <= dlen)
		return (size + slen);
	while (src[i] != '\0' && dlen + i < size - 1)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}

#include <stdio.h>
int main()
{
	char text1[20] = "123";
	char text2[] = "456789";
	unsigned int p;
	p = ft_strlcat(text1, text2, 20);
	printf("%d\n", p);
}