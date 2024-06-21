/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ops_rotates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:19:50 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/21 18:55:02 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_all *meta)
{
	ra(meta, 0);
	rb(meta, 0);
	ft_putstr("rr\n");
}

void	ra(t_all *meta, int x)
{
	t_stack	*one;
	t_stack	*last;
	t_stack	*zero;

	if (meta->ssa < 2)
		return ;
	zero = meta->stack_a;
	one = zero->next;
	last = zero->prev;
	zero->next = zero->next->next;
	zero->next->prev = zero;
	zero->prev = one;
	one->next = zero;
	last->next = one;
	one->prev = last;
	reindex_a(meta);
	if (x)
		ft_putstr("ra\n");
}

void	rb(t_all *meta, int x)
{
	t_stack	*one;
	t_stack	*last;
	t_stack	*zero;

	if (meta->ssb < 2)
		return ;
	zero = meta->stack_b;
	while (zero->pos != 0)
		zero = zero->next;
	one = zero->next;
	last = zero->prev;
	zero->next = zero->next->next;
	zero->next->prev = zero;
	zero->prev = one;
	one->next = zero;
	last->next = one;
	one->prev = last;
	reindex_b(meta);
	if (x)
		ft_putstr("rb\n");
}
