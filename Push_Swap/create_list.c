/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmachado <bmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:19:45 by bmachado          #+#    #+#             */
/*   Updated: 2021/06/24 17:55:26 by bmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_input(char *e_stack)
{
	int	i;

	i = 0;
	if (!e_stack)
		return (0);
	if (e_stack[i] == '-' && e_stack[i + 1])
		i++;
	while (e_stack[i])
	{
		if (ft_isdigit(e_stack[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

static int	has_repeated(long int *array, int number, int array_size)
{
	int	i;

	i = -1;
	while (++i < array_size)
		if (array[i] == number)
			return (1);
	return (0);
}

int	stack_repeated(t_list *stack_a)
{
	long int	*malloc_stack;
	int			stack_size;
	int			i;

	stack_size = ft_lstsize(stack_a);
	malloc_stack = malloc(sizeof(long int) * stack_size);
	if (!malloc_stack)
		return (0);
	i = 0;
	while (i < stack_size)
	{
		malloc_stack[i] = ctoi(stack_a);
		if (has_repeated(malloc_stack, malloc_stack[i], i))
		{
			free(malloc_stack);
			return (1);
		}
		stack_a = stack_a->next;
		i++;
	}
	free(malloc_stack);
	return (0);
}

static long long	ft_atol(const char *str)
{
	long long	holder;
	long long	sign;

	holder = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		holder = holder * 10 + *str - '0';
		str++;
	}
	return (holder * sign);
}

int	makelist(t_list **stack_a, int argc, char **argv)
{
	int				i;
	long long int	*malloc_stack;
	t_list			*current;

	i = 0;
	while (++i < argc)
	{
		malloc_stack = malloc(sizeof(int));
		if (!malloc_stack)
			return (0);
		if (!is_valid_input(argv[i]))
			return (-1);
		*malloc_stack = ft_atol(argv[i]);
		if (*malloc_stack > INT_MAX || *malloc_stack < INT_MIN)
			return (-1);
		ft_lstadd_front(stack_a, ft_lstnew(malloc_stack));
	}
	return (1);
}
