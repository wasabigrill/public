/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhang <zzhang@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:56:28 by zzhang            #+#    #+#             */
/*   Updated: 2026/02/25 13:21:12 by zzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

// static void print_list(array *lst)
// {
// 	while (lst)
// 	{
// 		printf("nb:%d idx:%d \n", lst->data, lst->index);
// 		lst = lst->next;
// 	}
// }

void	ft_sort(array **a, array **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		ft_sort2(a);
	else if (size == 3)
		ft_sort3(a);
	else if (size == 4)
		ft_sort4(a, b);
	else if (size == 5)
		ft_sort5(a, b);
	else
		ft_big_sort(a, b);
}

int	main(int c, char **args)
{
	array	**a;
	array	**b;

	if (!check_error(c, args))
		exit(0);
	a = (array **) ft_calloc(1, sizeof(array *));
	b = (array **) ft_calloc(1, sizeof(array *));
	if (!a || !b)
		return (-1);
	if (c == 2 && ft_strchr(args[1], ' '))
	{
		args = ft_split(args[1], ' ');
		if (!args)
			return (-1);
		*a = initialise_stack(count_word(args[1], ' '), args);
		free_double_pointer(args);
	}
	else
		*a = initialise_stack(c - 1, args + 1);
	if (!*a)
		return (-1);
	ft_sort(a, b);
	// print_list(*a);
	// // printf("sorting %d\n", is_sorted(*a));
	// printf("printf stack b:\n");
	// print_list(*b);
	ft_lstclear(a);
	ft_lstclear(b);
	free(a);
	free(b);
	return (0);
}