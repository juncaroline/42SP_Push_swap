/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:57:13 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/12 14:38:53 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 2)
		******free();
	while (++i < ac)
	{
		j = 0;
		if (!av[i][0] || (av[i][0] && av[i][0] == ' '))
			******free();
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' ' && 
				av[i][j] != ' ' && av[i][j] != '+')
				******free();
			j++;
			else if ((av[i][j] == '-' || av[i][j] == '+') &&
				(av[i][j + 1] == '\0' || av[i][j + 1] == ' '))
				******free();
			j++;
		}
	}
}

void normalize(t_stack *list)
{
	int	i;
	int	j;
	int	k;
	int	*temp;

	temp = malloc(list->sizea * sizeof *temp);
	if (temp == NULL)
		******return (NULL);
	i = -1;
	while (++i < list->sizea)
	{
		k = 0;
		j = -1;
		while (++j < list->sizea)
			if
	}
}
