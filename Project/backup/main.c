/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:21:28 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/16 12:51:14 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_exit_msg(t_stack *stack, char *msg)
{
	if (msg)
		write (2, msg, ft_strlen(msg));
	if (stack != NULL)
	{
		if (stack->a != NULL)
			free(stack->a);
		if (stack->b != NULL)
			free(stack->b);
		if (stack != NULL)
			free(stack);
	}
	exit(1);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	check_args(ac, av);
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		exit (1);
	initialize(ac, av, stack);
	exit_duplicate(stack, 0);
	normalize(stack);
	if (stack->sizea == 2 && stack->a[0] > stack->a[1])
		swap("sa", stack);
	else if (stack->sizea == 3)
		sort_three(stack);
	else if (stack->sizea == 4 || stack->sizea == 5)
		sort_four_five(stack);
	else
		radix_sort(stack);
	is_sorted(stack);
	free_exit_msg(stack, NULL);
	return (0);
}
