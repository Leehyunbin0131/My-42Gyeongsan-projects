/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:00:19 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/02 16:20:29 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (i < n && (s1[i] == s2[i]) && s1[i])
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return (s1[i] - s2[i]);
}

#include <stdio.h>
int main() {
   char str1[] = "appa";
   char str2[] = "app";
   char str3[] = "zanana";

   printf("%d\n", ft_strncmp(str1, str2, 3)); 
   printf("%d\n", ft_strncmp(str1, str3, 3));
   printf("%d\n", ft_strncmp(str3, str1, 3));

   return 0;
}