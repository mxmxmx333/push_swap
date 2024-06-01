/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:25:25 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/01 16:10:20 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_pos_pos(t_all *meta, t_stack *to_push, t_stack *target)
{
	while (to_push->pos != 1  && target->pos != 1)
		rrr(meta);
	while (to_push->pos != 1)
		rra(meta, 1);
	while (target->pos != 1)
		rrb(meta, 1);
	pb(meta);
}
void	a_neg_neg(t_all *meta, t_stack *to_push, t_stack *target)
{
	while (to_push->pos != 1  && target->pos != 1)
		rr(meta);
	while (to_push->pos != 1)
		ra(meta, 1);
	while (target->pos != 1)
		rb(meta, 1);
	pb(meta);
}
void	a_pos_neg(t_all *meta, t_stack *to_push, t_stack *target)
{
	while (to_push->pos != 1)
		rra(meta, 1);
	while (target->pos != 1)
		rb(meta, 1);	
	pb(meta);
}

void	a_neg_pos(t_all *meta, t_stack *to_push, t_stack *target)
{
	while (to_push->pos != 1)
		ra(meta, 1);
	while (target->pos != 1)
		rrb(meta, 1);
	pb(meta);
}
