/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:16:12 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/13 18:38:45 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(char *type, t_stack *stack)
{
	int	temp;

	if (ft_strncmp(type, "ra", 3) == 0)
	{
		temp = stack->a[0];
		ft_memmove(stack->a, stack->a + 1, sizeof(int) * (stack->sizea - 1));
        stack->a[stack->sizea - 1] = temp;
        ft_putendl_fd("ra", 1);
	}
	else if (ft_strncmp(type, "rb", 3) == 0)
	{
		temp = stack->b[0];
		ft_memmove(stack->b, stack->b + 1, sizeof(int) * (stack->sizeb - 1));
        stack->b[stack->sizeb - 1] = temp;
        ft_putendl_fd("rb", 1);
	}
}

void	rotate_both(char *str, t_stack *stack, char **last_move)
{
	if(ft_strncmp(str, "ra", 3) == 0 || ft_strncmp(str, "rb", 3) == 0)
	{
		rotate(str, stack);
		if (*last_move && (
            (ft_strncmp(*last_move, "ra", 3) == 0 &&
            ft_strncmp(str, "rb", 3) == 0) ||
			(ft_strncmp(*last_move, "rb", 3) == 0 &&
            ft_strncmp(str, "ra", 3) == 0)))
		{
			rotate("ra", stack);
			rotate("rb", stack);
			ft_putendl_fd("rr", 1);
			*last_move = NULL;
		}
		else
		{
			ft_putendl_fd(str, 1);
			*last_move = str;
		}
	}
}

