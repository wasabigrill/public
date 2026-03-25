/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_array_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhang <zzhang@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:35:06 by zzhang            #+#    #+#             */
/*   Updated: 2026/02/25 13:15:24 by zzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_insert_pos(array *a, int idx_b)
{
	int	distance;
	int i;
	int	pos;
	int	idx_a;

	i = 0;
	pos = 0;
	distance = abs(idx_b - a->index);
	idx_a = a->index;
	while (a)
	{
		if (distance > abs(idx_b - a->index))
		{
			distance = abs(idx_b - a->index);
			pos = i;
			idx_a = a->index;
		}
		a = a->next;
		i++;
	}
	if (idx_a > idx_b)
		return (pos);
	else
		return (pos + 1);
}

static int max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static void	cal_cost(array *a, array *b, int *position_a, int *position_b, int *cost)
{
	int pos_a;
	int pos_b;
	int size_b;

	pos_b = 0;
	size_b = ft_lstsize(b);
	while (b)
	{
		pos_a = find_insert_pos(a, b->index);
		// b->cost = min(abs(pos_a - pos_b) + min(pos_a, pos_b), 
				// abs(pos_a - pos_b) + min(ft_lstsize(a) - pos_a, size_b - pos_b));
		b->cost = min(max(pos_a, pos_b), max(ft_lstsize(a) - pos_a, size_b - pos_b));
		b->cost = min(b->cost, 
				min((pos_a + size_b - pos_b), (ft_lstsize(a) - pos_a + pos_b)));

		if (*cost > b->cost)
		{
			*cost = b->cost;
			*position_a = pos_a;
			*position_b = pos_b;
		}
		b = b->next;
		pos_b++;
	}
}

static void	rotate_together(array **a, array **b, int pos_a, int pos_b)
{
	// if (min(pos_a, pos_b) < min(ft_lstsize(*a) - pos_a, ft_lstsize(*b) - pos_b))
	if (max(pos_a, pos_b) < max(ft_lstsize(*a) - pos_a, ft_lstsize(*b) - pos_b))
	{
		while (pos_a > 0 && pos_b > 0)
		{
			rr(a, b);
			pos_a--;
			pos_b--;
		}
		while (pos_a-- > 0)
			ra(a);
		while (pos_b-- > 0)
			rb(b);
	}
	else
	{
		while (ft_lstsize(*a) - pos_a > 0 && ft_lstsize(*b) - pos_b > 0)
		{
			rrr(a, b);
			pos_a++;
			pos_b++;
		}
		while (ft_lstsize(*a) - pos_a++ > 0)
			rra(a);
		while (ft_lstsize(*b) - pos_b++ > 0)
			rrb(b);
	}
}

static void	rotate_seperately(array **a, array **b, int pos_a, int pos_b)
{
	if ((pos_a + ft_lstsize(*b) - pos_b) < (ft_lstsize(*a) - pos_a + pos_b))
	{
		while (pos_a-- > 0)
			ra(a);
		while (ft_lstsize(*b)- pos_b++ > 0)
			rrb(b);
	}
	else
	{
		while (pos_b-- >0)
			rb(b);
		while (ft_lstsize(*a) - pos_a++ >0)
			rra(a);
	}
}

void	insert_back(array **a, array **b)
{
	int pos_a;
	int pos_b;
	int cost;

	if (!a || !b || !*b)
		return;
	pos_a = 0;
	pos_b = 0;
	cost = ft_lstsize(*a) +  ft_lstsize(*b);
	cal_cost(*a, *b, &pos_a, &pos_b, &cost);
	// printf("size_a is %d, size_b is %d, posA is %d, posB is %d, cost is %d\n", ft_lstsize(*a), ft_lstsize(*b), pos_a, pos_b, cost);
	// printf("cost1 is %d, cost3 is %d and cost3 is %d\n\n", max(pos_a, pos_b), 
	// max(ft_lstsize(*a) - pos_a, ft_lstsize(*b) - pos_b),
	// min((pos_a + ft_lstsize(*b) - pos_b), (ft_lstsize(*a) - pos_a + pos_b)));
	if (cost == min((pos_a + ft_lstsize(*b) - pos_b), (ft_lstsize(*a) - pos_a + pos_b)))
		rotate_seperately(a, b, pos_a, pos_b);
	else
		rotate_together(a, b, pos_a, pos_b);
	pa(a, b);
}