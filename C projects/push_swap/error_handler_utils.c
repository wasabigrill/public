/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzhang <zzhang@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:11:52 by zzhang            #+#    #+#             */
/*   Updated: 2026/02/19 09:29:17 by zzhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_minint(char *str)
{
	const char *int_min = "2147483648";

	if (*str != '-')
		return (0);
	str++;
	while (*str)
	{
		if (*str > *int_min)
			return (0);
		int_min++;
		str++;
	}
	return (1);
}

static int check_maxint(char *str)
{
	const char *int_max = "2147483647";

	while (*str)
	{
		if (*str > *int_max)
			return (0);
		str++;
		int_max++;
	}
	return (1);
}

//check is it is valid number
int	check_format(char *str)
{
	if (*str == '-')
		str++;
	if (!*str)
		return (0);
	if (*str == '0' && *(str + 1))
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

// check if str is within limits between max_int and min_int
int check_limit(char *str)
{
	if (ft_strlen(str) > 11)
		return (0);
	else if (ft_strlen(str) == 11)
		return (check_minint(str));
	else if (ft_strlen(str) == 10 && *str != '-')
		return (check_maxint(str));
	else
		return (1);
}

int	check_duplicate(char *str, int size, char **array)
{
	while (--size >=0)
	{
		if (ft_atoi(str) == ft_atoi(array[size]))
			return (0);
	}
	return (1);
}