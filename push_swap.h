/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstinghe <dstinghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 21:20:43 by dstinghe          #+#    #+#             */
/*   Updated: 2024/06/07 00:52:41 by dstinghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			stack;
	int				num;
	struct s_list	*next;
}					t_list;

/** Main **/
int					main(int ac, char **av);

/** Input Processing **/
int					single_str(char *str, int *arr, long long num);
long long			str_to_long(char **str);

/** Utils **/
void				print_string(char *str);
int					num_valid(char *str);
void				free_all(int *arr, t_list **list_a, t_list **list_b,
						int error);
int					duplicate(t_list **list, int *a, int size);
int					ascending(t_list **list);

/** Linked Lists **/
void				free_list(t_list **list_a);
int					init_list(t_list **list, int *a, int size);
void				rotate_list(t_list **list, char direction);
int					list_len(t_list **list);
void				push_or_swap(t_list **src, t_list **dest, char command,
						char stack);

/** Algorithm **/
void				sort_three(t_list **list_a, t_list **list_b);
int					closest_num(t_list **list, int num, int close,
						char direction);
int					min_max(t_list **list, char c);
int					cost_move_to_top(t_list **list, int num);
int					total_cost(t_list **list_a, t_list **list_b, int num_a,
						int num_b);
void				single_stack_rotate(t_list **list, int num);
void				stack_rotate(t_list **list_b, t_list **list_a, int num_b,
						int num_a);
void				push_sort_stack(t_list **list_to, t_list **list_from,
						char c, int loop_stop);
int					sorter(int *arr, int size);

#endif