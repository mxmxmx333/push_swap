/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:32:53 by mbonengl          #+#    #+#             */
/*   Updated: 2024/05/30 18:56:20 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_all *meta)
{
	int		temp;
	t_stack	*one;
	t_stack	*two;

	if (meta->ssa < 3)
		return ;
	one = meta->stack_a;
	while (one->pos != 1)
		one = one->next;
	two = one->next;
	temp = one->number;
	one->number = two->number;
	two->number = temp;
}

void	sb(t_all *meta)
{
	int		temp;
	t_stack	*one;
	t_stack	*two;

	if (meta->ssb < 3)
		return ;
	one = meta->stack_b;
	while (one->pos != 1)
		one = one->next;
	two = one->next;
	temp = one->number;
	one->number = two->number;
	two->number = temp;
}

void	ss(t_all *meta)
{
	sa(meta);
	sb(meta);
}