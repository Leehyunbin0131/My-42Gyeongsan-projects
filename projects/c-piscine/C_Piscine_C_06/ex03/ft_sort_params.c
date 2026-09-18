/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:31:28 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/05 15:21:42 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str);
int	ft_strcmp(char *s1, char *s2);
int	sort(int size, char **arr);

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

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

int	sort(int size, char **arr)
{
	int		k;
	int		n;
	char	*pik;

	n = 0;
	while (n < size)
	{
		k = 1;
		while (k < size - 1)
		{
			if (ft_strcmp(arr[k], arr[k + 1]) > 0)
			{
				pik = arr[k + 1];
				arr[k + 1] = arr[k];
				arr[k] = pik;
			}
			k++;
		}
		n++;
	}
	return (0);
}

int	main(int ag, char **av)
{
	int	k;
	int	n;

	k = 1;
	n = 0;
	if (ag < 2)
		return (0);
	sort(ag, av);
	while (k < ag)
	{
		n = ft_strlen(av[k]);
		write(1, av[k], n);
		write(1, "\n", 1);
		k++;
	}
	return (0);
}
