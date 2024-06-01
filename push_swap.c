/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:50:52 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/01 16:56:08 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_all *meta)
{
	t_stack	*stack_a;
	int		num1;
	int		num2;
	int		num3;

	stack_a = meta->stack_a->next;
	num1 = stack_a->number;
	num2 = stack_a->next->number;
	num3 = stack_a->next->next->number;
	if (num1 < num2 && num2 > num3 && num3 > num1)
	{
		sa(meta, 1);
	}
	else if (num1 > num2 && num2 < num3 && num3 > num1)
	{
		sa(meta, 1);
	}
}

void	push_swap(t_all *meta)
{
	push_to_b(meta);
	sort_three(meta);
}