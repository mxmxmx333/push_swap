/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ops_pushes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:27:59 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/21 18:30:43 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// unattaching from stack a
void	connect(t_stack *first, t_stack *second)
{
	first->next = second;
	second->prev = first;
}

void	unattach_a(t_stack *topush, t_all *meta)
{
	t_stack	*previous;
	t_stack	*next;

	previous = topush->prev;
	next = topush->next;
	if (previous == next)
	{
		previous->next = NULL;
		previous->prev = NULL;
	}
	else
	{
		connect(previous, next);
	}
	reindex_a(meta);
}

// unattaching from stack b
void	unattach_b(t_stack *topush, t_all *meta)
{
	t_stack	*previous;
	t_stack	*next;

	previous = topush->prev;
	next = topush->next;
	if (previous == next)
	{
		previous->next = NULL;
		previous->prev = NULL;
	}
	else
	{
		connect(previous, next);
	}
	reindex_b(meta);
}

//takes from b to a
void	pa(t_all *meta)
{
	t_stack	*zero;
	t_stack	*to_push;
	t_stack	*one;

	to_push = meta->stack_b;
	if (to_push->next == NULL)
		return ;
	to_push = to_push->next;
	unattach_b(to_push, meta);
	zero = meta->stack_a;
	if (zero->next)
	{
		one = zero->next;
		connect(zero, to_push);
		connect(to_push, one);
	}
	else
	{
		connect(zero, to_push);
		connect(to_push, zero);
	}
	reindex_a(meta);
	meta->ssb--;
	meta->ssa++;
	ft_putstr("pa\n");
}

//push from a to b
void	pb(t_all *meta)
{
	t_stack	*zero;
	t_stack	*to_push;
	t_stack	*one;

	to_push = meta->stack_a;
	if (to_push->next == NULL)
		return ;
	to_push = to_push->next;
	unattach_a(to_push, meta);
	zero = meta->stack_b;
	if (zero->next)
	{
		one = zero->next;
		connect(zero, to_push);
		connect(to_push, one);
	}
	else
	{
		connect(zero, to_push);
		connect(to_push, zero);
	}
	reindex_b(meta);
	meta->ssa--;
	meta->ssb++;
	ft_putstr("pb\n");
}
