/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:51:26 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/02 16:25:23 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find);
int		check_len(char *str);

int	check_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	len;
	int	j;
	int	i;

	i = 0;
	j = 0;
	len = 0;
	if (to_find[0] == '\0')
		return (str);
	len = check_len(to_find);
	while (str[i] != '\0')
	{
		while (to_find[j] != '\0' && str[i + j] == to_find[j])
			j++;
		if (j == len)
			return (&str[i]);
		else
			j = 0;
		i++;
	}
	return (NULL);
}

#include <stdio.h>
int main() {
	char text[] = "123124";
	char search[] = "999";
	char* result = ft_strstr(text, search);
	if (result) {
		printf("찾은 위치: %s\n", result);
	} else {
		printf("문자열을 찾을 수 없습니다.\n");
	}
	return 0;
}