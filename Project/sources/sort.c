/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:41:11 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/16 09:12:00 by cabo-ram         ###   ########.fr       */
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
			reverse_rotate("ra", stack);
	}
	if (stack->a[0] > stack->a[1])
		swap("sa", stack);
}

void	sort_four_five(t_stack *stack)
{
	while (stack->sizeb <= 1)
	{
		if (stack->a[0] == 0 || stack->a[0] == 1)
			push("pb", stack);
		else
			rotate("ra", stack);
	}
	if (stack->b[0] == 0)
		swap ("sb", stack);
	if (stack->a[2] != 4)
	{
		if (stack->a[0] == 4)
			rotate("ra", stack);
		else
			reverse_rotate("ra", stack);
	}
	if (stack->a[0] > stack->a[1])
		swap("sa", stack);
	push ("pa", stack);
	push ("pa", stack);
}

