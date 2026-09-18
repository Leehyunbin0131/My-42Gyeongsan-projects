/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:58:51 by hyunlee           #+#    #+#             */
/*   Updated: 2026/02/08 21:00:01 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;

int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
t_dict	*create_dict(char *dict_path);
char	*get_word(t_dict *dict, char *key);
int		count_line(char *buffer, int fd, int *total_bytes);
char	*ft_strndup(char *src, int n);
int		split_lines(char **lines, char *full_content);
int		parse_line(char *str, t_dict *tmp);
int		get_dict(char **lines, int count, t_dict *dicts);
int		is_valid_number(char *str);
char	*skip_zeros(char *str);
int		print_under_100(t_dict *dict, int n);
int		print_group(t_dict *dict, int n);
int		split_number(char *str, int *groups);
int		print_number(t_dict *dict, char *str, int *groups);
char	*make_unit_key(int index);
int		print_unit(t_dict *dict, int i);
int		print_one_group(t_dict *dict, int group, int i, int *printed);
int		has_duplicate_key(t_dict *dict);
int		open_and_count(char *dict_path, int *total);
char	*read_content(char *dict_path, int total);
int		validate_number(t_dict *dict, char *str, int *groups);
int		validate_unit(t_dict *dict, int i);

#endif
