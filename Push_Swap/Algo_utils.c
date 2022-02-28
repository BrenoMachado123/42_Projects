/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:00:46 by bmachado          #+#    #+#             */
/*   Updated: 2021/07/09 11:57:16 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	divide_stack(t_list **stack_1, t_list **stack_2, int closest)
{
	t_list	*current;
	int		count;

	count = 0;
	if (!(*stack_1))
		return (count);
	while (!is_bigger(*stack_1, closest))
	{
		current = ft_lstlast(*stack_1);
		if (ctoi(current) <= closest && ++count)
			pb(stack_1, stack_2);
		else
			ra(stack_1);
	}
	return (count);
}

int	divide_stack_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int		closest;
	int		count;

	count = 0;
	closest = find_closest_term(*stack_b);
	if (!(*stack_b))
		return (0);
	while (*stack_b)
	{
		current = ft_lstlast(*stack_b);
		if (ctoi(current) >= closest)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
		if (is_smaller(*stack_b, closest))
			break ;
	}
	return (count);
}

void	sort_order(t_list *sorted)
{
	t_list	*current;
	void	*tmp;

	if (!sorted)
		return ;
	current = sorted;
	while (current->next)
	{
		if (*((int *)(current->next->content)) > *((int *)(current->content)))
		{
			tmp = current->next->content;
			current->next->content = current->content;
			current->content = tmp;
			sort_order(sorted);
			break ;
		}
		current = current->next;
	}
}

int	find_closest_term(t_list *stack)
{
	t_list		*tmp_stack;
	t_list		*current;
	long int	*tmp_number;
	int			i;

	if (!stack)
		return (0);
	tmp_stack = NULL;
	while (stack)
	{
		tmp_number = malloc(sizeof(long int));
		if (!tmp_number)
			return (0);
		*tmp_number = ctoi(stack);
		ft_lstadd_front(&tmp_stack, ft_lstnew(tmp_number));
		stack = stack->next;
	}
	sort_order(tmp_stack);
	i = -1;
	while (++i < ((ft_lstsize(tmp_stack)) / 2))
		tmp_stack = tmp_stack->next;
	i = ctoi(tmp_stack);
	ft_lstclear(&tmp_stack, free);
	return (i);
}
