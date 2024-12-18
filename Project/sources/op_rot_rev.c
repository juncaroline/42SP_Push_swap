/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rot_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:16:12 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/18 10:53:31 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(char *type, t_stack *stack)
{
	int	temp;

	if (!stack)
		return ;
	if (ft_strncmp(type, "ra", 2) == 0 && stack->sizea > 1)
	{
		temp = stack->a[0];
		ft_memmove(stack->a, stack->a + 1, sizeof(int) * (stack->sizea - 1));
		stack->a[stack->sizea - 1] = temp;
		ft_putendl_fd("ra", 1);
	}
	else if (ft_strncmp(type, "rb", 2) == 0 && stack->sizeb > 1)
	{
		temp = stack->b[0];
		ft_memmove(stack->b, stack->b + 1, sizeof(int) * (stack->sizeb - 1));
		stack->b[stack->sizeb - 1] = temp;
		ft_putendl_fd("rb", 1);
	}
}

void	rotate_both(char *str, t_stack *stack, char **last_move)
{
	if ((ft_strncmp(str, "ra", 2) == 0 || ft_strncmp(str, "rb", 2) == 0)
		&& stack->sizea > 1 && stack->sizeb > 1)
	{
		if (last_move && *last_move && (
				(ft_strncmp(*last_move, "ra", 2) == 0
					&& ft_strncmp(str, "rb", 2) == 0)
				|| (ft_strncmp(*last_move, "rb", 2) == 0
					&& ft_strncmp(str, "ra", 2) == 0)))
		{
			rotate("ra", stack);
			rotate("rb", stack);
			ft_putendl_fd("rr", 1);
			*last_move = "";
		}
		else
		{
			rotate(str, stack);
			ft_putendl_fd(str, 1);
			*last_move = str;
		}
	}
}

void	reverse_rotate(char *type, t_stack *stack)
{
	int	temp;

	if (ft_strncmp(type, "rra", 3) == 0 && stack->sizea > 1)
	{
		temp = stack->a[stack->sizea - 1];
		ft_memmove(stack->a + 1, stack->a, sizeof(int) * (stack->sizea - 1));
		stack->a[0] = temp;
		ft_putendl_fd("rra", 1);
	}
	else if (ft_strncmp(type, "rrb", 3) == 0 && stack->sizeb > 1)
	{
		temp = stack->b[stack->sizeb - 1];
		ft_memmove(stack->b + 1, stack->b, sizeof(int) * (stack->sizeb - 1));
		stack->b[0] = temp;
		ft_putendl_fd("rrb", 1);
	}
}

void	reverse_rotate_both(char *str, t_stack *stack, char **last_move)
{
	if ((ft_strncmp(str, "rra", 3) == 0 || ft_strncmp(str, "rrb", 3) == 0)
		&& stack->sizea > 1 && stack->sizeb > 1)
	{
		if (last_move && *last_move && (
				(ft_strncmp(*last_move, "rra", 3) == 0
					&& ft_strncmp(str, "rrb", 3) == 0)
				|| (ft_strncmp(*last_move, "rrb", 3) == 0
					&& ft_strncmp(str, "rra", 3) == 0)))
		{
			reverse_rotate("rra", stack);
			reverse_rotate("rrb", stack);
			ft_putendl_fd("rrr", 1);
			*last_move = "";
		}
		else
		{
			reverse_rotate(str, stack);
			ft_putendl_fd(str, 1);
			*last_move = str;
		}
	}
}
