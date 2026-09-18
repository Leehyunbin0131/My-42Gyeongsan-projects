/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:14:50 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/02 14:48:45 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str);
void	check_alp(char *str, int *flag);

void	check_alp(char *str, int *flag)
{
	int	is_lowalp;
	int	is_num;
	int	is_sp;
	int	is_op;

	is_lowalp = (*str >= 'a' && *str <= 'z');
	is_num = (*str >= '0' && *str <= '9');
	is_sp = (*str == ' ');
	is_op = (!is_lowalp && !is_num && !is_sp);
	if (is_sp)
		*flag = 1;
	else if (is_num)
		*flag = 0;
	else if (is_op)
		*flag = 1;
	else if (*flag && is_lowalp)
	{
		*str = *str - 32;
		*flag = 0;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	n;
	int	flag;

	n = 0;
	flag = 1;
	while (str[n] != '\0')
	{
		if (str[n] >= 'A' && str[n] <= 'Z')
		{
			str[n] = str[n] + 32;
		}
		n++;
	}
	n = 0;
	while (*(str + n) != '\0')
	{		
		check_alp(str + n, &flag);
		n++;
	}
	return (str);
}

#include <stdio.h>
int main()
{
	char src[] = "Hi, HOW aRe yoU? 42words forty-Two; fifty+And+one";
	printf("%s", ft_strcapitalize(src));
}