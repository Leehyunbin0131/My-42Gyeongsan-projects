/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:17:06 by chwang            #+#    #+#             */
/*   Updated: 2026/02/01 15:23:42 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_number(char num);

static int	check_digit(char c, int *count)
{
	int	value;

	value = is_number(c);
	if (value == -1)
		return (0);
	*count += 1;
	return (1);
}

static int	is_possible_count(int count)
{
	int	i;

	i = 4;
	while (i <= 9)
	{
		if (4 * i == count)
			return (i);
		i += 1;
	}
	return (-88);
}

int	validate_input(int input_count, char **input_values)
{
	int	i;
	int	ready;
	int	count;

	if (input_count != 2)
		return (-88);
	i = 0;
	ready = 1;
	count = 0;
	while (input_values[1][i] != '\0')
	{
		if (ready == 1 && !check_digit(input_values[1][i], &count))
			return (-88);
		if (ready == -1 && input_values[1][i] != ' ')
			return (-88);
		ready *= -1;
		i += 1;
	}
	return (is_possible_count(count));
}
