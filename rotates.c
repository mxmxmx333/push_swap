/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:19:50 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/01 16:03:41 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_all *meta)
{
	ra(meta, 0);
	rb(meta, 0);
}

void	ra(t_all *meta, int x)
{
	t_stack	*one;
	t_stack	*last;
	t_stack	*zero;
	int		temp;

	if (meta->ssa < 2)
		return ;
	zero = meta->stack_a;
	// while (zero->pos != 0)
	// 	zero = zero->next;
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
	int		temp;

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

