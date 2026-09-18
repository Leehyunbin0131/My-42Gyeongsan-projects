/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:36:15 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/02 16:17:15 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

#include <stdio.h>
int main() {
    char str1[] = "apple";
    char str2[] = "apple";
    char str3[] = "banana";

    printf("%d\n", ft_strcmp(str1, str2)); 
    printf("%d\n", ft_strcmp(str1, str3));
    printf("%d\n", ft_strcmp(str3, str1));

    return 0;
}