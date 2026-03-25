/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhang <zzhang@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:07:58 by zzhang            #+#    #+#             */
/*   Updated: 2026/02/25 13:15:41 by zzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(array **a, array **b)
{
	array	*tmp;

	if (b && *b)
	{
		tmp = (*b)->next;
		ft_lstadd_front(a, *b);
		*b = tmp;
	}
}
void	pa(array **a, array **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(array **a, array **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}