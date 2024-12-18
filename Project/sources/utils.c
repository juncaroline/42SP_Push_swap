/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:57:13 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/18 10:10:37 by cabo-ram         ###   ########.fr       */
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
			i++;
		}
	}
	if (is_sorted(stack))
		free_exit_msg(stack, NULL);
}

int	ft_atol(const char *str, t_stack *stack)
{
	int			i;
	long		neg;
	long long	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	if (ft_strlen(str) > 11)
		free_exit_msg(stack, "Error\n");
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			free_exit_msg(stack, "Error\n");
		res = res * 10 + (str[i++] - '0');
		if ((neg == 1 && res > INT_MAX) || (neg == -1 && (res * neg) < INT_MIN))
			free_exit_msg(stack, "Error\n");
	}
	return ((int)(res * neg));
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
		stack->a[j++] = ft_atol(temp[i], stack);
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
		free_exit_msg(stack, "Error\n");
	stack->b = malloc(stack->sizea * sizeof(*stack->b));
	if (stack->b == NULL)
		free_exit_msg(stack, "Error\n");
}
