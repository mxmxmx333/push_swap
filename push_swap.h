/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:10:19 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/01 13:19:40 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h> /*size_t, malloc, free*/
#include <limits.h> //limits

typedef struct s_stack
{
	int				number;
	size_t			pos;
	size_t			cost;
	int				dir_a;
	int				dir_b;
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
	size_t	ssa;
	size_t	ssb;
	t_ops	*ops;
}	t_all;

/*input & filling*/
void	fill_stack_a(size_t argc, char **argv, t_all *meta);
int		is_filled_a(t_all *meta);
void	create_stack_b(t_all *meta);

/*meta_utils*/
void	free_meta(t_all *meta);
void	reindex_a(t_all *meta);
void	reindex_b(t_all *meta);

/*basic utils*/
int		ft_atoi(const char *nptr);

/*ops*/
//rotations
void	ra(t_all *meta);
void	rb(t_all *meta);
void	rr(t_all *meta);
void	rrr(t_all *meta);
void	rra(t_all *meta);
void	rrb(t_all *meta);
//pushes
void	pa(t_all *meta);
void	pb(t_all *meta);
//swaps
void	sa(t_all *meta);
void	sb(t_all *meta);
void	ss(t_all *meta);

/*targeting*/
void	get_all_targets_a(t_all *meta);

/*costs*/
void	put_direction(t_stack *node, int a, int b);
void	getcosts_a(t_all *meta);

/*input control*/

/*sorting*/

/*main functions*/

#endif