/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:20:22 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/13 15:46:41 by cabo-ram         ###   ########.fr       */
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

#endif