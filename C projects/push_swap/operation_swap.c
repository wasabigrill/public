/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhang <zzhang@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:07:17 by zzhang            #+#    #+#             */
/*   Updated: 2026/02/25 13:15:49 by zzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(array **a)
{
	array *second_node;

	if (!*a || !(*a)->next)
		return;
	second_node = (*a)->next;
	(*a)->next = (*a)->next->next;
	second_node->next = *a;
	*a = second_node;
}
void	sa(array **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(array **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(array **a, array **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
