/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunlee <hyunlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:06:14 by lhb               #+#    #+#             */
/*   Updated: 2026/05/04 15:26:54 by hyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*list_node;
	void	*node_content;

	list_node = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst != NULL)
	{
		node_content = f(lst->content);
		new_node = ft_lstnew(node_content);
		if (new_node == NULL)
		{
			del(node_content);
			ft_lstclear(&list_node, del);
			return (NULL);
		}
		ft_lstadd_back(&list_node, new_node);
		lst = lst->next;
	}
	return (list_node);
}
