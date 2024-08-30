/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:35:58 by dyao              #+#    #+#             */
/*   Updated: 2024/06/19 17:39:03 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	new_lst = NULL;
	while (lst)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
		{
			while (new_lst)
			{
				del(new_lst->content);
				free(new_lst);
				new_lst = new_lst->next;
			}
			return (NULL);
		}
		new_node->content = f(lst->content);
		new_node->next = new_lst;
		new_lst = new_node;
		lst = lst->next;
	}
	return (new_lst);
}
