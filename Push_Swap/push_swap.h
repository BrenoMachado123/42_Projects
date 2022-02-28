/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:37:30 by bmachado          #+#    #+#             */
/*   Updated: 2021/07/09 13:05:00 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		get_max(t_list *stack);
int		get_min(t_list *stack);
int		is_valid_input(char *e_stack);
int		ctoi(t_list *stack);
int		makelist(t_list **stack_a, int argc, char **argv);
int		stack_repeated(t_list *stack_a);
int		is_sorted(t_list *stack);
int		min_location(t_list **stack_a);
int		ismax_close_to_end(t_list **stack_a);
int		ismin_close_to_end(t_list **stack_a);
int		find_closest_term(t_list *stack);
int		is_smaller(t_list *stack, int closest);
int		is_bigger(t_list *stack, int n);
int		divide_stack(t_list **stack_1, t_list **stack_2, int closest);
int		divide_stack_b(t_list **stack_a, t_list **stack_b);

void	push(t_list **stack_1, t_list **stack_2);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

void	swap(t_list *stack);
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);

void	rotate(t_list **stack_a);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

void	reverse_rotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

void	exit_program(t_list **stack_a, t_list **stack_b, int exit_error);
void	display_stacks(t_list *stack_a, t_list *stack_b);
void	max_in_first(t_list **stack_a);

void	sort_small_stack(t_list **stack_a, t_list **stack_b);
void	sort_big_stack(t_list **stack_a, t_list **stack_b);

void	sort_order(t_list *sorted);

void	reach_max(t_list **stack, int ab);
void	reach_min(t_list **stack, int ab);

#endif
