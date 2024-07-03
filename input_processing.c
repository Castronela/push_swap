/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstinghe <dstinghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:52:13 by dstinghe          #+#    #+#             */
/*   Updated: 2024/06/07 00:36:27 by dstinghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	single_str(char *str, int *arr, long long num)
{
	int	num_c;
	int	i;

	num_c = num_valid(str);
	if (num_c == 0)
		return (0);
	else if (num_c < 0)
		return (free_all(NULL, NULL, NULL, 1), 1);
	arr = malloc(num_c * sizeof(int));
	if (!arr)
		return (free_all(NULL, NULL, NULL, 1), 1);
	i = 0;
	while (i < num_c)
	{
		if (*str == '-' || (*str >= '0' && *str <= '9'))
		{
			num = str_to_long(&str);
			if (num < INT_MIN || num > INT_MAX)
				return (free_all(arr, NULL, NULL, 1), 1);
			arr[i++] = (int)num;
		}
		str++;
	}
	return (sorter(arr, num_c));
}

long long	str_to_long(char **str)
{
	long long	num_sign[2];
	long long	multiplier;
	int			len;
	int			i;

	num_sign[1] = 1;
	if (**str == '-')
	{
		(*str)++;
		num_sign[1] = -num_sign[1];
	}
	len = 0;
	while ((*str)[len] && (*str)[len] != ' ')
		len++;
	num_sign[0] = 0;
	while (len > 0)
	{
		multiplier = 1;
		i = --len;
		while (i-- > 0)
			multiplier *= 10;
		num_sign[0] += (**str - '0') * multiplier;
		(*str)++;
	}
	return (num_sign[0] * num_sign[1]);
}
