/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:10:19 by mbonengl          #+#    #+#             */
/*   Updated: 2024/05/24 13:13:37 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h> /*size_t, malloc, free*/
#include <limits.h>

typedef struct s_stack
{
	int				number;
	size_t			pos;
	size_t			cost;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_ops
{
	char			*str;
	struct s_ops	*next;
}	t_ops;

typedef struct s_all
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_ops	*ops;
}	t_all;

void	fill_stack_a(size_t argc, char **argv, t_all *meta);
void	clearstack(t_all *meta);
int		ft_atoi(const char *nptr);


#endif