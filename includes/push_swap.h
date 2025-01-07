/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:20:22 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/07 15:47:12 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libraries/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_stack
{
	long	*a;
	long	*b;
	int		sizea;
	int		sizeb;
	char	*receive_args;
}			t_stack;

void	check_args(int ac, char **av);
void	normalize(t_stack *stack);
void	exit_sorted_duplicate(t_stack *stack, int i);
int		count(char const *number, char c);
void	initialize(int ac, char **av, t_stack *stack);
void	swap(char *type, t_stack *stack);
void	push(char *type, t_stack *s);
void	rotate(char *type, t_stack *stack);
void	reverse_rotate(char *type, t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_four_five(t_stack *stack);
int		is_sorted(t_stack *stack);
void	radix_sort(t_stack *stack);
void	free_exit_msg(t_stack *stack, char *msg);
void	parse(t_stack *stack);
long	ft_atol(const char *str);
int		main(int ac, char **av);

#endif