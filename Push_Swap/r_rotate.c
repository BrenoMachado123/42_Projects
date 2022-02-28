/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:07:35 by bmachado          #+#    #+#             */
/*   Updated: 2021/06/24 15:09:49 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*stack_a) || !((*stack_a)->next))
		return ;
	tmp = *stack_a;
	cp = (*stack_a)->next;
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = tmp;
	tmp->next = NULL;
	*stack_a = cp;
}

void	rra(t_list **stack_a)
{
	r_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **stack_b)
{
	r_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
