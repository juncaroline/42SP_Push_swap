/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:40:02 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/07 15:55:40 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(char *type, t_stack *stack)
{
	int	temp;

	if (!type || !stack)
		return ;
	if (!ft_strncmp(type, "sa", 2) && stack->sizea > 1)
	{
		temp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = temp;
		ft_putendl_fd("sa", 1);
	}
	else if (!ft_strncmp(type, "sb", 2) && stack->sizeb > 1)
	{
		temp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = temp;
		ft_putendl_fd("sb", 1);
	}
}

void	push(char *type, t_stack *stack)
{
	int	temp;

	if (!type || !stack || !stack->a || !stack->b)
		return ;
	if (ft_strncmp(type, "pa", 3) == 0 && stack->sizeb > 0)
	{
		temp = stack->b[0];
		ft_memmove(stack->a + 1, stack->a, sizeof(long) * stack->sizea);
		stack->a[0] = temp;
		stack->sizeb--;
		ft_memmove(stack->b, stack->b + 1, sizeof(long) * stack->sizeb);
		stack->sizea++;
	}
	else if (ft_strncmp(type, "pb", 3) == 0 && stack->sizea > 0)
	{
		temp = stack->a[0];
		ft_memmove(stack->b + 1, stack->b, sizeof(long) * stack->sizeb);
		stack->b[0] = temp;
		stack->sizea--;
		ft_memmove(stack->a, stack->a + 1, sizeof(long) * stack->sizea);
		stack->sizeb++;
	}
	ft_putendl_fd(type, 1);
}

void	rotate(char *type, t_stack *stack)
{
	int	temp;

	if (!type || !stack)
		return ;
	if (ft_strncmp(type, "ra", 2) == 0 && stack->sizea > 1)
	{
		temp = stack->a[0];
		ft_memmove(stack->a, stack->a + 1, sizeof(long) * (stack->sizea - 1));
		stack->a[stack->sizea - 1] = temp;
		ft_putendl_fd("ra", 1);
	}
	else if (ft_strncmp(type, "rb", 2) == 0 && stack->sizeb > 1)
	{
		temp = stack->b[0];
		ft_memmove(stack->b, stack->b + 1, sizeof(long) * (stack->sizeb - 1));
		stack->b[stack->sizeb - 1] = temp;
		ft_putendl_fd("rb", 1);
	}
}

void	reverse_rotate(char *type, t_stack *stack)
{
	int	temp;

	if (!type || !stack)
		return ;
	if (ft_strncmp(type, "rra", 3) == 0 && stack->sizea > 1)
	{
		temp = stack->a[stack->sizea - 1];
		ft_memmove(stack->a + 1, stack->a, sizeof(long) * (stack->sizea - 1));
		stack->a[0] = temp;
		ft_putendl_fd("rra", 1);
	}
	else if (ft_strncmp(type, "rrb", 3) == 0 && stack->sizeb > 1)
	{
		temp = stack->b[stack->sizeb - 1];
		ft_memmove(stack->b + 1, stack->b, sizeof(long) * (stack->sizeb - 1));
		stack->b[0] = temp;
		ft_putendl_fd("rrb", 1);
	}
}
