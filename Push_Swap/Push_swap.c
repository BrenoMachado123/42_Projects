/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:21:43 by bmachado          #+#    #+#             */
/*   Updated: 2021/07/09 13:04:29 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		is_list;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	is_list = makelist(&stack_a, argc, argv);
	if (argc == 1)
		exit_program(&stack_a, &stack_b, 0);
	if (is_list < 0 || stack_repeated(stack_a))
		exit_program(&stack_a, &stack_b, 1);
	else if (is_sorted(stack_a))
		exit_program(&stack_a, &stack_b, 0);
	if (ft_lstsize(stack_a) == 2)
		sa(stack_a);
	else if (ft_lstsize(stack_a) <= 5)
		sort_small_stack(&stack_a, &stack_b);
	else
		sort_big_stack(&stack_a, &stack_b);
	exit_program(&stack_a, &stack_b, 0);
}
