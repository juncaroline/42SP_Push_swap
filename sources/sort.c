/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:41:11 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/07 15:46:39 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack *stack)
{
	if (stack->a[2] != 2)
	{
		if (stack->a[0] == 2)
			rotate("ra", stack);
		else
			reverse_rotate("rra", stack);
	}
	if (stack->a[0] > stack->a[1])
		swap("sa", stack);
}

void	sort_four_five(t_stack *stack)
{
	while (stack->sizeb < 2)
	{
		if (stack->a[0] == 0 || stack->a[0] == 1)
			push("pb", stack);
		else
			rotate("ra", stack);
	}
	if (stack->sizeb > 0 && stack->b[0] == 0)
		swap("sb", stack);
	if (stack->sizea > 2 && stack->a[2] != 4)
	{
		if (stack->a[0] == 4)
			rotate("ra", stack);
		else
			reverse_rotate("rra", stack);
	}
	if (stack->a[0] > stack->a[1])
		swap("sa", stack);
	push ("pa", stack);
	push ("pa", stack);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	if (stack->sizea <= 1)
		return (1);
	i = 0;
	while (i < stack->sizea - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	radix_stackb(t_stack *stack, int sizeb, int bit_size, int j)
{
	while (sizeb-- && j <= bit_size && !is_sorted(stack))
	{
		if (stack->sizeb > 0 && ((stack->b[0] >> j) & 1) == 0)
			rotate("rb", stack);
		else
			push("pa", stack);
	}
	if (is_sorted(stack))
		while (stack->sizeb != 0)
			push("pa", stack);
}

void	radix_sort(t_stack *stack)
{
	int		j;
	int		bit_size;
	int		size;

	bit_size = 0;
	size = stack->sizea;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = stack->sizea;
		while (size-- && !is_sorted(stack))
		{
			if (((stack->a[0] >> j) & 1) == 0)
				push("pb", stack);
			else
				rotate("ra", stack);
		}
		radix_stackb(stack, stack->sizeb, bit_size, j + 1);
	}
	while (stack->sizeb != 0)
		push("pa", stack);
}
