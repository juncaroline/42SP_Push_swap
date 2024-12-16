/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:21:28 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/16 17:06:14 by cabo-ram         ###   ########.fr       */
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
		if (stack != NULL)
			free(stack);
	}
	exit(1);
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

int	ft_atol(const char *str, t_stack *stack)
{
	int			i;
	long		neg;
	long long	res;

	i = 0;
	neg = 1;
	res = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (str[i])
	{
		if (res > INT_MAX || (res * neg) < INT_MIN || ft_strlen(str) > 11)
			free_exit_msg(stack, "Error\n");
		if (!(str[i] >= '0' && str[i] <= '9'))
			free_exit_msg(stack, "Error\n");
		res = res * 10 + (str[i++] - '0');
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
	i = 0;
	while (temp[i] != NULL && temp[i][0] != '\0')
	{
		stack->a[j++] = ft_atol(temp[i++], stack);
		free(temp[i - 1]);
	}
	free(temp);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	check_args(ac, av);
	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		exit (1);
	initialize(ac, av, stack);
	receive_args(ac, av, stack);
	parse(stack);
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
	if (is_sorted(stack))
		free_exit_msg(stack, NULL);
	return (0);
}
