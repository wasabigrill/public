/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhang <zzhang@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:54:59 by zzhang            #+#    #+#             */
/*   Updated: 2026/02/23 12:47:39 by zzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

typedef struct t_element
{
	int	data;
	int	index;
	int	size;
	int cost;
	struct t_element	*next;
}	array;

// operation functions
void	sa(array **a);
void	sb(array **b);
void	ss(array **a, array **b);
void	pa(array **a, array **b);
void	pb(array **a, array **b);
void	ra(array **a);
void	rb(array **b);
void	rr(array **a, array **b);
void	rra(array **a);
void	rrb(array **b);
void	rrr(array **a, array **b);

// check input error
int check_error(int c, char **args);
int	check_format(char *str);
int check_limit(char *str);
int	check_duplicate(char *str, int size, char **array);

// functions for linked-list
array	*ft_lstnew(int content);
void	ft_lstadd_front(array **lst, array *new_lst);
int		ft_lstsize(array *lst);
array	*ft_lstlast(array *lst);
void	ft_lstadd_back(array **lst, array *new_lst);
void	ft_lstdelone(array *lst);
void	ft_lstclear(array **lst);

// additional utilities functions
void	free_double_pointer(char **args);
int		count_word(char const *s, char c);
int		find_pos(array *lst, int idx);
int		min(int a, int b);
int		abs(int a);


// intialise stacks
array	*initialise_stack(int size, char **args);
void	initialise_stack_index(array *a);

// sorting function
void	ft_sort(array **a, array **b);
void	ft_sort2(array **lst);
void	ft_sort3(array **lst);
void	ft_sort4(array **a, array **b);
void	ft_sort5(array **a, array **b);
void	ft_sort_big_array(array **a, array **b);

int		sorted (array *lst);

// testing functions for big_sort
void	ft_big_sort(array **a, array **b);
void	insert_back(array **a, array **b);

#endif
