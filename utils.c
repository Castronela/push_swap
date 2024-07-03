/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstinghe <dstinghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:04:12 by dstinghe          #+#    #+#             */
/*   Updated: 2024/06/07 02:05:20 by dstinghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_string(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

// return count of numbers in array
// or -1 if invalid input (other chars or bad sign placement)
int	num_valid(char *str)
{
	int	i;
	int	num_c;

	num_c = 0;
	if (str[0] > 32 && str[0] < 127)
		num_c++;
	i = 0;
	while (str[++i])
	{
		if ((str[i - 1] == 32) && (str[i] > 32 && str[i++] < 127))
			num_c++;
	}
	while (*str)
	{
		if ((*str < '0' || *str > '9') && (*str != ' ') && (*str != '-')
			&& (*str != '+'))
			num_c = -1;
		else if ((*str == '-' || *str == '+') && (str[1] < '1' || str[1] > '9'))
			num_c = -1;
		else if ((*str >= '0' && *str <= '9') && (str[1] != ' ' && str[1]
				&& (str[1] < '0' || str[1] > '9')))
			num_c = -1;
		str++;
	}
	return (num_c);
}

void	free_all(int *arr, t_list **list_a, t_list **list_b, int error)
{
	if (arr)
		free(arr);
	if (list_a)
	{
		free_list(list_a);
		free(list_a);
	}
	if (list_b)
	{
		free_list(list_b);
		free(list_b);
	}
	if (error)
		print_string("Error\n");
}

int	ascending(t_list **list)
{
	t_list	*current_node;

	current_node = *list;
	while (current_node->next)
	{
		if (current_node->num > (current_node->next)->num)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}

int	duplicate(t_list **list, int *a, int size)
{
	t_list	*current_node;
	int		i;
	int		j;

	j = 0;
	current_node = *list;
	while (current_node)
	{
		i = j + 1;
		while (i < size)
		{
			if (current_node->num == a[i])
				return (1);
			i++;
		}
		j++;
		current_node = current_node->next;
	}
	return (0);
}
