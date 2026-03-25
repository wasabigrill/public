/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhang <zzhang@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:40:19 by zzhang            #+#    #+#             */
/*   Updated: 2026/02/23 12:46:58 by zzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

array *initialise_stack(int size, char **args)
{
	int		i;
	array	*first_node;
	array	*new_lst;

	i = 0;
	if (size < 0 || !args)
		return (NULL);
	first_node = ft_lstnew(ft_atoi(args[i]));
	while (++i < size)
	{
		new_lst = ft_lstnew(ft_atoi(args[i]));
		if (!new_lst)
			return(ft_lstclear(&first_node), NULL);
		ft_lstadd_back(&first_node, new_lst);
	}
	initialise_stack_index(first_node);
	return (first_node);
}

int	find_pos(array *lst, int idx)
{
	int i;

	i = 0;
	while (lst)
	{
		if (lst->index == idx)
			return (i);
		i++;
		lst = lst->next;
	}
	return (-1);
}

void	free_double_pointer(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

int	count_word(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s++ != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
		{
			while (*s && *s == c)
				s++;
		}
	}
	return (count);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}
