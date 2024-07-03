/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstinghe <dstinghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:35:01 by dstinghe          #+#    #+#             */
/*   Updated: 2024/06/07 01:13:59 by dstinghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// execute rotation or reverse rotation of stack
// based on sign of cost
void	single_stack_rotate(t_list **list, int num)
{
	int	cost;

	cost = cost_move_to_top(list, num);
	while (cost)
	{
		if (cost > 0)
		{
			if ((*list)->stack == 'a')
				print_string("ra\n");
			else
				print_string("rb\n");
			rotate_list(list, 'u');
			cost--;
		}
		else if (cost < 0)
		{
			if ((*list)->stack == 'a')
				print_string("rra\n");
			else
				print_string("rrb\n");
			rotate_list(list, 'd');
			cost++;
		}
	}
}

// execute rotation or reverse rotation of both
// stacks based on sign of cost
void	stack_rotate(t_list **list_b, t_list **list_a, int num_b, int num_a)
{
	int	cost_a;
	int	cost_b;

	cost_a = cost_move_to_top(list_a, num_a);
	cost_b = cost_move_to_top(list_b, num_b);
	while (cost_a > 0 && cost_b > 0)
	{
		rotate_list(list_a, 'u');
		rotate_list(list_b, 'u');
		print_string("rr\n");
		cost_a--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rotate_list(list_a, 'd');
		rotate_list(list_b, 'd');
		print_string("rrr\n");
		cost_a++;
	}
	single_stack_rotate(list_a, num_a);
	single_stack_rotate(list_b, num_b);
}

// find the (pairs) of numbers from stack a and b which need the least
// ammount of instructions to be moved to the top of their stacks
// and execute the moves
//
// (pairs): for number from list_from, find closest smallest/highest number
// from list_to
void	push_sort_stack(t_list **list_to, t_list **list_from, char c,
		int loop_stop)
{
	t_list	*c_node;
	int		close;
	int		i;
	int		len;

	i = 0;
	len = list_len(list_from);
	while (len > loop_stop)
	{
		c_node = *list_from;
		while (c_node)
		{
			close = closest_num(list_to, c_node->num, min_max(list_to, c), c);
			if (i == total_cost(list_to, list_from, close, c_node->num))
			{
				stack_rotate(list_to, list_from, close, c_node->num);
				push_or_swap(list_from, list_to, 'p', c);
				i = -1;
				len--;
				break ;
			}
			c_node = c_node->next;
		}
		i++;
	}
}

// - push first number to stack b and start algorithm
// - numbers in stack b are sorted in descending order
// till stack a has 3 numbers left
// - execute sorting algorithm for 3 numbers in stack a
// - numbers in stack a are sorted in ascending order
// till stack b has no numbers left
int	sorter(int *arr, int size)
{
	t_list	**list_a;
	t_list	**list_b;

	if (size == 0)
		return (0);
	list_a = malloc(sizeof(t_list *));
	if (!list_a)
		return (free_all(arr, NULL, NULL, 1), 1);
	list_b = malloc(sizeof(t_list *));
	if (!list_b)
		return (free_all(arr, list_a, NULL, 1), 1);
	*list_a = NULL;
	*list_b = NULL;
	if (init_list(list_a, arr, size) || duplicate(list_a, arr, size))
		return (free_all(arr, list_a, list_b, 1), 1);
	if (!ascending(list_a))
	{
		if (list_len(list_a) > 3)
			push_or_swap(list_a, list_b, 'p', 'm');
		push_sort_stack(list_b, list_a, 'm', 3);
		sort_three(list_a, list_b);
		push_sort_stack(list_a, list_b, 'M', 0);
		single_stack_rotate(list_a, min_max(list_a, 'm'));
	}
	return (free_all(arr, list_a, list_b, 0), 0);
}
