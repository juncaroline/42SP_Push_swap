/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:57:13 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/07 16:24:00 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_sorted_duplicate(t_stack *stack, int i)
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
			if (stack->a[i] > INT_MAX || stack->a[i] < INT_MIN)
				free_exit_msg(stack, "Error\n");
			i++;
		}
	}
	if (is_sorted(stack))
		free_exit_msg(stack, NULL);
}

long	ft_atol(const char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * neg);
}

void	parse(t_stack *stack)
{
	char	**temp;
	int		i;
	int		j;

	j = 0;
	temp = ft_split(stack->receive_args, ' ');
	if (temp == NULL)
		free_exit_msg(stack, "Error\n");
	i = 0;
	while (temp[i] != NULL && temp[i][0] != '\0')
	{
		if (stack->a != NULL)
		{
			stack->a[j] = ft_atol(temp[i]);
			j++;
		}
		free(temp[i]);
		i++;
	}
	free(temp);
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
			stack->sizea++;
		i++;
	}
	stack->a = malloc(stack->sizea * sizeof(*stack->a));
	if (stack->a == NULL)
		return ;
	stack->b = malloc(stack->sizea * sizeof(*stack->b));
	if (stack->b == NULL)
		return ;
}
