#include "push_swap.h"

int	is_smaller(t_list *stack, int closest)
{
	t_list	*current;

	current = stack;
	while (stack)
	{
		if (ctoi(stack) > closest)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_bigger(t_list *stack, int n)
{
	t_list	*current;

	current = stack;
	while (current)
	{
		if (ctoi(current) <= n)
			return (0);
		current = current->next;
	}
	return (1);
}

void	reach_max(t_list **stack, int ab)
{
	if (ab == 1)
	{
		if (ismax_close_to_end(stack) == 1)
			while (ctoi(ft_lstlast(*stack)) != get_max(*stack))
				ra(stack);
		else if (ismax_close_to_end(stack) == 2)
			while (ctoi(ft_lstlast(*stack)) != get_max(*stack))
				rra(stack);
	}
	else
	{
		if (ismax_close_to_end(stack) == 1)
			while (ctoi(ft_lstlast(*stack)) != get_max(*stack))
				rb(stack);
		else if (ismax_close_to_end(stack) == 2)
			while (ctoi(ft_lstlast(*stack)) != get_max(*stack))
				rrb(stack);
	}
}

void	reach_min(t_list **stack, int ab)
{
	if (ab == 1)
	{
		if (ismin_close_to_end(stack) == 1)
			while (ctoi(ft_lstlast(*stack)) != get_min(*stack))
				ra(stack);
		else if (ismin_close_to_end(stack) == 2)
			while (ctoi(ft_lstlast(*stack)) != get_min(*stack))
				rra(stack);
	}
	else
	{
		if (ismin_close_to_end(stack) == 1)
			while (ctoi(ft_lstlast(*stack)) != get_min(*stack))
				rb(stack);
		else if (ismin_close_to_end(stack) == 2)
			while (ctoi(ft_lstlast(*stack)) != get_min(*stack))
				rrb(stack);
	}
}
