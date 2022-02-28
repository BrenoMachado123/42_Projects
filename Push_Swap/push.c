/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:16:31 by bmachado          #+#    #+#             */
/*   Updated: 2021/06/24 15:09:19 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*top;
	int		size;
	int		i;

	if (!(*stack_a))
		return ;
	size = ft_lstsize(*stack_a);
	tmp = *stack_a;
	i = 0;
	while (++i < size - 1)
		tmp = tmp->next;
	if (size == 1)
	{
		top = tmp;
		*stack_a = NULL;
	}
	else
	{
		top = tmp->next;
		tmp->next = NULL;
	}
	ft_lstadd_back(stack_b, top);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_b);
	if (size == 0)
		return ;
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 0)
		return ;
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}
