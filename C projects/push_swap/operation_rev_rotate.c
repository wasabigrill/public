/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rev_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhang <zzhang@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:45:24 by zzhang            #+#    #+#             */
/*   Updated: 2026/02/25 12:51:38 by zzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(array **a)
{
	array *last;
	array *node;

	node = *a;
	last = ft_lstlast(*a);
	while (node->next->next)
		node = node->next;
	node->next = NULL;
	ft_lstadd_front(a, last);
}

void	rra(array **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(array **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(array **a, array **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}