/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhang <zzhang@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:08:52 by zzhang            #+#    #+#             */
/*   Updated: 2026/02/25 13:15:46 by zzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(array **a)
{
	array	*tmp;

	if (a && *a)
	{
		tmp = *a;
		*a = (*a)->next;
		ft_lstadd_back(a, tmp);
	}
}

void	ra(array **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(array **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(array **a, array **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
