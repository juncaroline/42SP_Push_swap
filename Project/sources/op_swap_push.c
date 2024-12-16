/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:40:02 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/16 17:31:28 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(char *type, t_stack *stack)
{
	int	temp;

	if (!type || !stack)
		return;
	if (!ft_strncmp(type, "sa", 3) && stack->sizea > 1)
	{
		temp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = temp;
	}
	else if (!ft_strncmp(type, "sb", 3) && stack->sizeb > 1)
	{
		temp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = temp;
	}
}

void	swap_both(char *type, t_stack *stack, char **last_move)
{
	if (!type || !stack || !last_move)
		return;
	if (!ft_strncmp(type, "sa", 3) || !ft_strncmp(type, "sb", 3))
	{
		swap(type, stack);
		if (*last_move && ((!ft_strncmp(*last_move, "sa", 3)
					&& !ft_strncmp(type, "sb", 3))
				|| (!ft_strncmp(*last_move, "sb", 3)
					&& !ft_strncmp(type, "sa", 3))))
		{
			swap("sa", stack);
			swap("sb", stack);
			ft_putendl_fd("ss", 1);
			*last_move = NULL;
		}
		else
		{
			ft_putendl_fd(type, 1);
			*last_move = type;
		}
	}
}

void	push(char *type, t_stack *stack)
{
	int	temp;

	if (!type || !stack || !stack->a || !stack->b)
		return;
	if (ft_strncmp(type, "pa", 3) == 0 && stack->sizeb <= 0)
	{
		temp = stack->b[0];
		ft_memmove(stack->a + 1, stack->a, sizeof(int) * stack->sizea);
		stack->a[0] = temp;
		stack->sizeb--;
		ft_memmove(stack->b, stack->b + 1, sizeof(int) * stack->sizeb);
		stack->sizea++;
	}
	else if (ft_strncmp(type, "pb", 3) == 0 && stack->sizea <= 0)
	{
		temp = stack->a[0];
		ft_memmove(stack->b + 1, stack->b, sizeof(int) * stack->sizeb);
		stack->b[0] = temp;
		stack->sizea--;
		ft_memmove(stack->a, stack->a + 1, sizeof(int) * stack->sizea);
		stack->sizeb++;
	}
}
