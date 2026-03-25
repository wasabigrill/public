/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_array_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhang <zzhang@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 05:22:14 by zzhang            #+#    #+#             */
/*   Updated: 2026/02/25 12:02:43 by zzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	array *find_first_to_push(array *a, int max_idx)
{
	while (a && a->index >= max_idx)
		a = a->next;
	return (a);
}

static array *find_last_to_push(array *a, int max_idx)
{
	array *last_to_push;

	last_to_push = NULL;
	while (a)
	{
		if (a->index < max_idx)
			last_to_push = a;
		a = a->next;	
	}
	return (last_to_push);
}

static int	idx_in_array(array *a, int max_idx)
{
	while (a)
	{
		if (a->index < max_idx)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	push_index_smaller(array **a, array **b, int max_idx)
{
	array	*first_to_push;
	array	*last_to_push;
	int		pos1;
	int		pos2;

	first_to_push = find_first_to_push(*a, max_idx);
	last_to_push = find_last_to_push(*a, max_idx);
	pos1 = find_pos(*a, first_to_push->index);
	pos2 = find_pos(*a, last_to_push->index);
	if (pos1 < pos2 && (ft_lstsize(*a) - pos2 > pos1))
	{
		while ((*a) != first_to_push)
			ra(a);
	}
	else
	{
		while ((*a) != last_to_push)
			rra(a);
	}
	pb(b, a);
}

// static void	push_max_index(array **a, array **b, int total_size)
// {
// 	int max_idx;
// 	int	pos;

// 	max_idx = total_size - 4;
// 	while (b && max_idx >= 0)
// 	{
// 		pos = find_pos(*b, max_idx);
// 		if (pos < ft_lstsize(*b) / 2)
// 		{
// 			while ((*b)->index != max_idx)
// 				rb(b);
// 		}
// 		else
// 		{
// 			while ((*b)->index != max_idx)
// 				rrb(b);
// 		}
// 		pa(a, b);
// 		max_idx--;
// 	}
// }

static void	put_smallest_on_top(array **a)
{
	int pos;

	pos = find_pos(*a, 0);
	if (pos < ft_lstsize(*a) / 2)
	{
		while ((*a)->index != 0)
			ra(a);
	}
	else
	{
		while ((*a)->index != 0)
			rra(a);
	}
}

void	ft_sort_big_array(array **a, array **b)
{
	int	i;
	int	total;
	int chunk_size;

	total = ft_lstsize(*a);
	i = 0;
	chunk_size = 20;
	while (ft_lstsize(*a) > chunk_size)
	{
		i++;
		while (idx_in_array(*a, chunk_size * i))
			push_index_smaller(a, b, chunk_size * i);
	}
	while (ft_lstsize(*a) > 3)
		push_index_smaller(a, b, total - 3);
	ft_sort3(a);
	// push_max_index(a, b, total);
	while (*b)
	{
		insert_back(a, b);
		// printf("print list A:\n");
		// print_list(*a);
		// printf("print list B:\n");
		// print_list(*b);
	}
	put_smallest_on_top(a);
}