/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_array_sort_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhang <zzhang@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:22:53 by zzhang            #+#    #+#             */
/*   Updated: 2026/02/25 13:22:05 by zzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	find_ordered_nbs(array *a, array *sub_lst, int size_max)
{
	array *a_cpy;

	a_cpy = a;
	if (!sub_lst)
		return (size_max);
	sub_lst->size = 1;
	while (a != sub_lst)
	{
		if (a->index < sub_lst->index && sub_lst->size < a->size + 1)
			sub_lst->size = a->size + 1;
		if (sub_lst->size > size_max)
			size_max = sub_lst->size;
		a = a->next;
	}
	return (find_ordered_nbs(a_cpy, sub_lst->next, size_max));
}


/* after finding the longest list of numbers are in ascending order, (size_max)
	find the position of this nb and push the rest before this nb to b;
*/
static int	find_tail_idx(array *a, int next_idx, int size, int end_pos)
{
	int idx_max;

	idx_max = 0;
	while (end_pos > 0)
	{
		if (a->size == size && a->index > idx_max && a->index < next_idx)
			idx_max = a->index;
		a = a->next;
		end_pos--;
	}
	return (idx_max);
}

static int	*nb_not_to_push(array *a)
{
	int *arr;
	int	size_max;
	int i;
	int end_pos;

	size_max = find_ordered_nbs(a, a, 0);
	i = size_max - 1;
	end_pos = ft_lstsize(a) - 1;
	arr = (int *) ft_calloc(size_max - 1, sizeof(int));
	if (!arr)
		return (NULL);
	arr[i--] = find_tail_idx(a, end_pos + 1, size_max--, end_pos + 1);
	while (i >= 0)
	{
		arr[i] = find_tail_idx(a, arr[i + 1], size_max, end_pos);
		end_pos = find_pos(a, arr[i]);
		size_max--;
		i--;
	}
	return (arr);
}

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

// static void print_list(array *lst)
// {
// 	while (lst)
// 	{
// 		printf("nb:%d idx:%d, size: %d\n", lst->data, lst->index, lst->size);
// 		lst = lst->next;
// 	}
// }

// static void print_arr(int *arr, int size)
// {
// 	int i = 0;
// 	while (i < size)
// 		printf("%d ", arr[i++]);
// 	printf("\n");
// }
void	ft_big_sort(array **a, array **b)
{
	int *arr;
	int i;
	int size;

	if (!a || !b || sorted(*a))
		return;
	arr = nb_not_to_push(*a);
	size = find_ordered_nbs(*a, *a, 0);
	i = 0;
	// print_arr(arr, size);
	if (!arr)
		return;
	while (ft_lstsize(*a) > size)
	{
		if (i < size && (*a)->index == arr[i])
		{
			ra(a);
			i++;
		}
		else
			pb(b, a);
	}
	// print_list(*a);
	// printf("finished \n");
	// exit(0);
	while (*b)
	{
		insert_back(a, b);
		// printf("print list A:\n");
		// print_list(*a);
		// printf("print list B:\n");
		// print_list(*b);
	}
	put_smallest_on_top(a);
	free(arr);
}
