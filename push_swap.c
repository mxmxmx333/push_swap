/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:04:37 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/01 14:26:50 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_to_push_a(t_all *meta)
{
	t_stack	*current;
	t_stack	*to_push;
	
}

void	push_to_b(t_all *meta)
{
	t_stack	*to_push;
	t_stack	*target;
	
	while (meta->ssa > 4 && meta->ssb < 4)
		pb(meta);
	while (meta->ssa > 4)
	{
		getcosts_a(meta);
		to_push = get_to_push_a(meta);
	}
}
