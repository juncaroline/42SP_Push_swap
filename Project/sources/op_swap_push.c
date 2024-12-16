/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:40:02 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/16 12:36:32 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(char *type, t_stack *stack)
{
	int	temp;

	if (!ft_strncmp(type, "sa", 3) && stack->sizea > 1)
	{
		temp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = temp;
	}
}

void	swap_both(char *type, t_stack *stack, char **last_move)
{
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

void	push(char *type, t_stack *s)
{
	int	temp;

	if (ft_strncmp(type, "pa", 3) == 0)
	{
		if (s->sizeb <= 0)
			return ;
		temp = s->b[0];
		ft_memmove(s->a + 1, s->a, sizeof(int) * s->sizea);
		s->a[0] = temp;
		s->sizeb--;
		ft_memmove(s->b, s->b + 1, sizeof(int) * s->sizeb);
		s->sizea++;
	}
	else if (ft_strncmp(type, "pb", 3) == 0)
	{
		if (s->sizea <= 0)
			return ;
		temp = s->a[0];
		ft_memmove(s->b + 1, s->b, sizeof(int) * s->sizeb);
		s->b[0] = temp;
		s->sizea--;
		ft_memmove(s->a, s->a + 1, sizeof(int) * s->sizea);
		s->sizeb++;
	}
}
