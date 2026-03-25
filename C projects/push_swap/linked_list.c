/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhang <zzhang@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:50:57 by zzhang            #+#    #+#             */
/*   Updated: 2026/02/19 10:53:54 by zzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

array	*ft_lstnew(int content)
{
	array	*lst;

	lst = (array *) ft_calloc(1, sizeof(array));
	if (!lst)
		return (NULL);
	lst->data = content;
	return (lst);
}

void	 ft_lstadd_front(array **lst, array *new_lst)
{
	if (lst)
	{
		new_lst->next = *lst;
		*lst = new_lst;
	}
}

int	ft_lstsize(array *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

array	*ft_lstlast(array *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(array **lst, array *new_lst)
{
	array	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new_lst;
		}
		else
			*lst = new_lst;
		new_lst->next = NULL;
	}
}

void	ft_lstdelone(array *lst)
{
	if (lst)
		free(lst);
}

void	ft_lstclear(array **lst)
{
	array *node;

	if (lst)
	{
		while (*lst)
		{
			node = (*lst)->next;
			ft_lstdelone(*lst);
			*lst = node;
		}
	}
}
