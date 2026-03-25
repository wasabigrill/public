/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhang <zzhang@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 08:42:44 by zzhang            #+#    #+#             */
/*   Updated: 2026/02/10 17:44:22 by zzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_stdin(int size, char **array)
{
	char	*str;

	while (--size >= 0)
	{
		str = array[size];
		if (!check_format(str))
			return (0);
		if (!check_limit(str))
			return (0);
		if (!check_duplicate(str, size, array))
			return (0);
	}
	return (1);
}

// this check the input $ARG start with a 
// number and each number spaced with only one ' '
// and it has to end with a number as well.
// if conditions are satisfied, it passes to valid_stdin for futher checking. 

static int	valid_single_input_format(char *str)
{
	int		size;

	size = 0;
	if (*str == '-')
		str++;
	if(!ft_isdigit(*str))
		return (0);
	while (*str)
	{
		if (*str == '-' && ft_isdigit(*(str + 1)))
			str++;
		else if (ft_isdigit(*str))
		{
			size++;
			while (ft_isdigit(*str))
				str++;
		}
		else if (*str == ' ' && (*(str + 1) == '-' || ft_isdigit(*(str + 1))))
			str++;
		else
			return (0);
	}
	return (size);
}

static int	valid_single_input(char *str)
{
	char	**args;
	int		size;

	if (!(size = valid_single_input_format(str)))
		return (0);
	args = ft_split(str, ' ');
	if (!args)
		return (0);
	if (valid_stdin(size, args))
		size = 1;
	else
		size = 0;
	free_double_pointer(args);
	return (size);
}

/*error need to be check
if no arguments are given, does not do anything
if argumetns not valid, in case of:
duplicates, non-number, over int limits(MAX_INT, MIN_INT)*/

int check_error(int c, char **args)
{
	if (c <= 1)
		return (0);
	else if (c == 2 && !valid_single_input(args[1]))
		return (write(1, "Error\n", 6), 0);
	else if (c > 2 && !valid_stdin(c - 1, args + 1))
		return (write(1, "Error\n", 6), 0);
	else
		return (1);
}