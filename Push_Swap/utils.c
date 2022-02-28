/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:05:14 by bmachado          #+#    #+#             */
/*   Updated: 2021/07/09 12:14:43 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_list *stack)
{
	t_list	*current;
	int		trigger;
	int		max;

	current = stack;
	trigger = 1;
	while (current)
	{
		if (trigger)
		{
			max = *(int *)(current->content);
			trigger--;
		}
		else if (max < *(int *)(current->content))
			max = *(int *)(current->content);
		current = current->next;
	}
	return (max);
}

int	get_min(t_list *stack)
{
	t_list	*current;
	int		trigger;
	int		min;

	current = stack;
	trigger = 1;
	while (current)
	{
		if (trigger)
		{
			min = *(int *)(current->content);
			trigger--;
		}
		else if (min > *(int *)(current->content))
			min = *(int *)(current->content);
		current = current->next;
	}
	return (min);
}

int	ctoi(t_list *stack)
{
	return (*((long int *)(stack->content)));
}

void	exit_program(t_list **stack_a, t_list **stack_b, int exit_error)
{
	if (exit_error == 1)
		ft_putstr_fd("Error\n", 1);
	if (stack_a)
		ft_lstclear(stack_a, free);
	if (stack_b)
		ft_lstclear(stack_b, free);
	exit(1);
}

void	display_stacks(t_list *stack_a, t_list *stack_b)
{
	t_list	*current;

	ft_putstr_fd("-------------------\n", 1);
	ft_putstr_fd("Stack A -> ", 1);
	current = stack_a;
	while (current)
	{
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(*((long int *)(current->content)), 1);
		current = current->next;
	}
	ft_putstr_fd("\nStack B -> ", 1);
	current = stack_b;
	while (current)
	{
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(*((long int *)(current->content)), 1);
		current = current->next;
	}
	ft_putstr_fd("\n-------------------\n", 1);
}
