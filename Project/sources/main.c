/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:21:28 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/23 09:32:34 by cabo-ram         ###   ########.fr       */
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
		if (stack->receive_args != NULL)
			free(stack->receive_args);
		free(stack);
	}
	exit(1);
}

void	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac < 2)
		free_exit_msg(NULL, "");
	while (i < ac)
	{
		j = 0;
		if (!av[i][0] || av[i][0] == ' ')
			free_exit_msg(NULL, "Error\n");
		while (av[i][j])
		{
			if (!(ft_isdigit(av[i][j])) && av[i][j] != ' '
				&& av[i][j] != '+' && av[i][j] != '-')
				free_exit_msg(NULL, "Error\n");
			else if ((av[i][j] == '-' || av[i][j] == '+')
				&& (av[i][j + 1] == '\0' || av[i][j + 1] == ' '))
				free_exit_msg(NULL, "Error\n");
			j++;
		}
		i++;
	}
}

static void	receive_args(int ac, char **av, t_stack *stack)
{
	char	*temp1;
	char	*temp2;
	int		i;

	i = 0;
	temp2 = ft_strdup("");
	while (++i < ac && av[i] != NULL)
	{
		temp1 = ft_strjoin(temp2, av[i]);
		if (temp2)
			free(temp2);
		if (i != ac - 1)
		{
			temp2 = ft_strjoin(temp1, " ");
			if (temp1)
				free(temp1);
			temp1 = temp2;
		}
	}
	stack->receive_args = ft_strdup(temp1);
	if (stack->receive_args == NULL)
		free_exit_msg(stack, "Error\n");
	if (temp1)
		free(temp1);
}

void	normalize(t_stack *stack)
{
	int	i;
	int	j;
	int	k;
	int	*temp;

	temp = malloc(stack->sizea * sizeof(*temp));
	if (temp == NULL)
		free_exit_msg(stack, "Error\n");
	i = -1;
	while (++i < stack->sizea)
	{
		k = 0;
		j = -1;
		while (++j < stack->sizea)
			if (stack->a[i] > stack->a[j])
				k++;
		temp[i] = k;
	}
	i = stack->sizea;
	while (i--)
		stack->a[i] = temp[i];
	free(temp);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	check_args(ac, av);
	stack = malloc(sizeof * stack);
	if (stack == NULL)
		exit (1);
	initialize(ac, av, stack);
	receive_args(ac, av, stack);
	parse(stack);
	exit_sorted_duplicate(stack, 0);
	normalize(stack);
	if (stack->sizea <= 1)
		free_exit_msg(stack, NULL);
	if (stack->sizea == 2 && stack->a[0] > stack->a[1])
		swap("sa", stack);
	else if (stack->sizea == 3)
		sort_three(stack);
	else if (stack->sizea == 4 || stack->sizea == 5)
		sort_four_five(stack);
	else
		radix_sort(stack);
	exit_sorted_duplicate(stack, 1);
	free_exit_msg(stack, NULL);
	return (0);
}
