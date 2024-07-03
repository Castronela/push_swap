/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstinghe <dstinghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:57:46 by dstinghe          #+#    #+#             */
/*   Updated: 2024/06/06 23:21:01 by dstinghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **list_a, t_list **list_b)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *list_a;
	second_node = first_node->next;
	while (!ascending(list_a))
	{
		if (first_node->num > second_node->num)
			push_or_swap(list_a, list_b, 's', 'M');
		else
		{
			rotate_list(list_a, 'd');
			print_string("rra\n");
		}
		first_node = *list_a;
		second_node = first_node->next;
	}
}

// direction == 'M'
// closest bigger number than num
// direction == 'm'
// closest smaller number than num
int	closest_num(t_list **list, int num, int close, char direction)
{
	t_list	*current_node;

	current_node = *list;
	while (direction == 'M' && current_node)
	{
		if (num >= close)
			return (min_max(list, 'm'));
		if (current_node->num > num && current_node->num < close)
			close = current_node->num;
		current_node = current_node->next;
	}
	while (direction == 'm' && current_node)
	{
		if (num < close)
			return (min_max(list, 'M'));
		if (current_node->num < num && current_node->num > close)
			close = current_node->num;
		current_node = current_node->next;
	}
	return (close);
}

// c == 'm'
// smallest number in list
// c == 'M'
// biggest number in list
int	min_max(t_list **list, char c)
{
	t_list	*current_node;
	int		num;

	current_node = *list;
	num = current_node->num;
	while (current_node)
	{
		if (c == 'm' && current_node->num < num)
			num = current_node->num;
		else if (c == 'M' && current_node->num > num)
			num = current_node->num;
		current_node = current_node->next;
	}
	return (num);
}

// return number of instructions to move num to top of stack
int	cost_move_to_top(t_list **list, int num)
{
	int		cost;
	int		len;
	t_list	*current_node;

	len = list_len(list);
	cost = 0;
	current_node = *list;
	while (current_node->num != num)
	{
		current_node = current_node->next;
		cost++;
	}
	if (cost <= (len / 2))
		return (cost);
	else
		return (cost - len);
}

// return number of instructions to move num_a from stack a
// and num_b from stack b to top of their stacks
int	total_cost(t_list **list_a, t_list **list_b, int num_a, int num_b)
{
	int	cost_a;
	int	cost_b;

	cost_a = cost_move_to_top(list_a, num_a);
	cost_b = cost_move_to_top(list_b, num_b);
	if ((cost_a <= 0 && cost_b <= 0) || (cost_a >= 0 && cost_b >= 0))
	{
		if (cost_a < 0 || cost_b < 0)
		{
			cost_a = -cost_a;
			cost_b = -cost_b;
		}
		if (cost_a < cost_b)
			return (cost_b);
		else
			return (cost_a);
	}
	else if (cost_a < 0)
		return (-cost_a + cost_b);
	else
		return (cost_a - cost_b);
}
