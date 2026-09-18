/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:29:54 by chwang            #+#    #+#             */
/*   Updated: 2026/02/01 19:29:27 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		print_error(int error_code);
int		validate_input(int input_count, char **input_values);
int		**make_map(int length, char *values);
int		**solution(int **map, int size);
void	print(int **arr, int num);

int	main(int argc, char **argv)
{
	int	validated_length;
	int	**input_arr;
	int	**result_arr;

	validated_length = validate_input(argc, argv);
	if (validated_length == -88)
	{
		print_error(validated_length);
		return (0);
	}
	input_arr = make_map(validated_length, argv[1]);
	result_arr = solution(input_arr, validated_length);
	print(result_arr, validated_length + 2);
	return (0);
}
