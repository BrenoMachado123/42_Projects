/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:08:30 by bmachado          #+#    #+#             */
/*   Updated: 2021/06/24 15:13:45 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack)
{
	t_list	*current;
	void	*tmp;
	int		size;
	int		i;

	if (!stack)
		return ;
	size = ft_lstsize(stack);
	current = stack;
	i = -1;
	while (++i < size - 2)
		current = current->next;
	tmp = current->content;
	current->content = current->next->content;
	current->next->content = tmp;
}

void	sa(t_list *stack_a)
{
	if (!stack_a || ft_lstsize(stack_a) == 1)
		return ;
	ft_putendl_fd("sa", 1);
	swap(stack_a);
}

void	sb(t_list *stack_b)
{
	if (!stack_b || ft_lstsize(stack_b) == 1)
		return ;
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_putendl_fd("ss", 1);
}
