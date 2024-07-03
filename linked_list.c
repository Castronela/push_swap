/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstinghe <dstinghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:30:19 by dstinghe          #+#    #+#             */
/*   Updated: 2024/06/07 00:07:48 by dstinghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list **list_a)
{
	t_list	*current_node;
	t_list	*next_node;

	if (*list_a)
	{
		current_node = *list_a;
		while (current_node)
		{
			next_node = current_node->next;
			free(current_node);
			current_node = NULL;
			current_node = next_node;
		}
	}
}

int	init_list(t_list **list, int *a, int size)
{
	t_list	*new;
	t_list	*last_node;
	int		i;

	i = 0;
	while (i < size)
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return (1);
		new->stack = 'a';
		new->num = a[i];
		new->next = NULL;
		if (!(*list))
			*list = new;
		else
			last_node->next = new;
		last_node = new;
		i++;
	}
	return (0);
}

void	rotate_list(t_list **list, char direction)
{
	t_list	*move_node;
	t_list	*modif_node;

	move_node = *list;
	if (direction == 'd')
	{
		while (move_node->next)
		{
			modif_node = move_node;
			move_node = move_node->next;
		}
		modif_node->next = NULL;
		move_node->next = *list;
		*list = move_node;
	}
	else if (direction == 'u')
	{
		modif_node = (*list)->next;
		*list = (*list)->next;
		while (modif_node->next)
			modif_node = modif_node->next;
		modif_node->next = move_node;
		move_node->next = NULL;
	}
}

int	list_len(t_list **list)
{
	t_list	*current_node;
	int		len;

	current_node = *list;
	len = 0;
	while (current_node)
	{
		current_node = current_node->next;
		len++;
	}
	return (len);
}

void	push_or_swap(t_list **src, t_list **dest, char command, char stack)
{
	t_list	*second_node;

	second_node = (*src)->next;
	if (command == 's')
	{
		(*src)->next = second_node->next;
		second_node->next = *src;
		print_string("sa\n");
	}
	else if (command == 'p')
	{
		(*src)->next = (*dest);
		*dest = *src;
		if (stack == 'M')
		{
			print_string("pa\n");
			(*dest)->stack = 'a';
		}
		else
		{
			print_string("pb\n");
			(*dest)->stack = 'b';
		}
	}
	*src = second_node;
}
