/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:40:39 by bmachado          #+#    #+#             */
/*   Updated: 2021/07/09 11:42:00 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_location(t_list **stack_a)
{
	int		i;
	t_list	*current;

	current = *stack_a;
	i = 0;
	while (ctoi(current) != get_max(*stack_a))
	{
		current = current->next;
		i++;
	}
	return (i);
}

int	min_location(t_list **stack_a)
{
	int		i;
	t_list	*current;

	current = *stack_a;
	i = 0;
	while (ctoi(current) != get_min(*stack_a))
	{
		current = current->next;
		i++;
	}
	return (i);
}

int	ismax_close_to_end(t_list **stack_a)
{
	t_list	*tmp;
	int		i;
	int		size;

	tmp = *stack_a;
	size = ft_lstsize(*stack_a) - 1;
	i = max_location(stack_a);
	if (size - i < size / 2)
		return (1);
	else
		return (2);
	return (0);
}

int	ismin_close_to_end(t_list **stack_a)
{
	t_list	*tmp;
	int		i;
	int		size;

	tmp = *stack_a;
	size = ft_lstsize(*stack_a) - 1;
	i = min_location(stack_a);
	if (size - i < size / 2)
		return (1);
	else
		return (2);
	return (0);
}
