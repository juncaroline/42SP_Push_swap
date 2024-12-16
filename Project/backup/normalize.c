/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:57:13 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/16 12:52:16 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		if (!av[i][0] || (av[i][0] && av[i][0] == ' '))
			free_exit_msg(NULL, "Error\n");
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' '
				&& av[i][j] != ' ' && av[i][j] != '+')
				free_exit_msg(NULL, "Error\n");
			else if ((av[i][j] == '-' || av[i][j] == '+')
				&& (av[i][j + 1] == '\0' || av[i][j + 1] == ' '))
				free_exit_msg(NULL, "Error\n");
			j++;
		}
		i++;
	}
}

void	normalize(t_stack *stack)
{
	int	i;
	int	j;
	int	k;
	int	*temp;

	temp = malloc(stack->sizea * sizeof * temp);
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

void	exit_duplicate(t_stack *stack, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < stack->sizea)
		{
			j = i + 1;
			while (j < stack->sizea)
			{
				if (stack->a[i] == stack->a[j])
					free_exit_msg(stack, "Error\n");
				j++;
			}
			i++;
		}
	}
}

int	count(char const *number, char c)
{
	int	count;

	count = 0;
	while (*number)
	{
		if (*number != c)
		{
			count++;
			while (*number && *number != c)
				number++;
		}
		else
			number++;
	}
	return (count);
}

void	initialize(int ac, char **av, t_stack *stack)
{
	int	i;

	i = 1;
	stack->sizea = 0;
	stack->sizeb = 0;
	while (i < ac)
	{
		if (count(av[i], ' '))
			stack->sizea += count(av[i], ' ');
		else
			i++;
	}
	stack->a = malloc(stack->sizea * sizeof * stack->a);
	if (stack->a == NULL)
		free_exit_msg(stack, "Error\n");
	stack->b = malloc(stack->sizea * sizeof * stack->b);
	if (stack->b == NULL)
		free_exit_msg(stack, "Error\n");
}
