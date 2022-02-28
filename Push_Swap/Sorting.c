/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:17:59 by bmachado          #+#    #+#             */
/*   Updated: 2021/07/09 12:18:43 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current->next)
	{
		if (ctoi(current->next) > ctoi(current))
			return (0);
		current = current->next;
	}
	return (1);
}

static int	sort_situations(t_list **stack_a)
{
	if (ctoi(ft_lstlast(*stack_a)) == get_max(*stack_a))
		return (1);
	else if (ctoi(*stack_a) != get_max(*stack_a))
		return (2);
	return (0);
}

static void	sort_three(t_list **stack_a)
{
	if (sort_situations(stack_a) == 1)
		ra(stack_a);
	if (sort_situations(stack_a) == 2)
		rra(stack_a);
	if (!is_sorted(*stack_a))
		sa(*stack_a);
}

void	sort_small_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(*stack_a);
	if (size != 3)
	{
		while (++i <= 2)
		{
			reach_min(stack_a, 1);
			pb(stack_a, stack_b);
		}
	}
	sort_three(stack_a);
	if (size != 3)
		while (++i <= 5)
			pa(stack_a, stack_b);
}

void	sort_big_stack(t_list **stack_a, t_list **stack_b)
{
	int	stack_div;
	int	last_element;
	int	prev_element;

	stack_div = 0;
	last_element = 0;
	prev_element = 0;
	if (!(*stack_a) || is_sorted(*stack_a))
		return ;
	while (!is_sorted(*stack_a))
	{
		prev_element = last_element;
		last_element = stack_div;
		stack_div = divide_stack(stack_a, stack_b, find_closest_term(*stack_a));
	}
	stack_div += last_element + prev_element;
	while (stack_div--)
	{
		reach_max(stack_b, 2);
		pa(stack_a, stack_b);
	}
	while (*stack_b)
		divide_stack_b(stack_a, stack_b);
	sort_big_stack(stack_a, stack_b);
}
