/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstinghe <dstinghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:29:44 by dstinghe          #+#    #+#             */
/*   Updated: 2024/06/07 01:31:46 by dstinghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	long long	num;
	int			*arr;
	int			i;

	arr = NULL;
	num = 0;
	if (ac == 2)
		return (single_str(av[1], arr, num));
	else if (ac > 2)
	{
		arr = malloc((ac - 1) * sizeof(int));
		if (!arr)
			return (free_all(NULL, NULL, NULL, 1), 1);
		i = 0;
		while (i < (ac - 1))
		{
			if (num_valid(av[i + 1]) < 0)
				return (free_all(arr, NULL, NULL, 1), 1);
			num = str_to_long(&(av[i + 1]));
			if (num < INT_MIN || num > INT_MAX)
				return (free_all(arr, NULL, NULL, 1), 1);
			arr[i++] = (int)num;
		}
	}
	return (sorter(arr, (ac - 1)));
}
