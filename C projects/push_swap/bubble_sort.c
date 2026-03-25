/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhang <zzhang@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:48:00 by zzhang            #+#    #+#             */
/*   Updated: 2026/02/17 14:00:53 by zzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int *arr, int size)
{
	int i;
	int	j;
	int	nb;

	j = 0;
	if (!arr || !size)
		return;
	while (j++ < size)
	{
		i = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				nb = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = nb;
			}
			i++;
		}
	}
}

static void	assign_index(int *arr, array *a)
{
	int		i;
	int		size;
	array	*lst;

	i = 0;
	size = ft_lstsize(a);
	lst = a;
	if (!arr || !a)
		return;
	while(i < size)
	{
		a = lst;
		while (a)
		{
			if (arr[i] == a->data)
			{
				a->index = i;
				break;
			}
			a = a->next;
		}
		i++;
	}
}

void	initialise_stack_index(array *a)
{
	int	*arr;
	int	i;
	array *lst;

	i = 0;
	lst = a;
	arr = (int *) ft_calloc(ft_lstsize(a), sizeof(int));
	if (!arr)
		return;
	while (lst)
	{
		arr[i++] = lst->data;
		lst = lst->next;
	}
	bubble_sort(arr, ft_lstsize(a));
	assign_index(arr, a);
	free(arr);
}