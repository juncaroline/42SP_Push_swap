/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:20:22 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/16 12:04:06 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../includes/libft.h"

#include <unistd.h>
#include <stdlib.h>

typedef struct	s_stack
{
	int	*a;
	int	*b;
	int	sizea;
	int	sizeb;
}	t_stack;

void 	normalize(t_stack *stack);
void	exit_duplicate(t_stack *stack, int i);
int		count(char const *number, char c);
void	initialize(int ac, char **av, t_stack *stack);
void	swap(char *type, t_stack *stack);
void	swap_both(char *type, t_stack *stack, char **last_move);
void	push(char *type, t_stack *s);
void	rotate(char *type, t_stack *stack);
void	rotate_both(char *str, t_stack *stack, char **last_move);
void	reverse_rotate(char *type, t_stack *stack);
void	reverse_rotate_both(char *str, t_stack *stack, char **last_move);
void	sort_three(t_stack *stack);
void	sort_four_five(t_stack *stack);
int		is_sorted(t_stack *stack);
void	radix_sort(t_stack *stack);
int		main(int ac, char **av);

#endif