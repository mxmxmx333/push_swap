/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:29:16 by mbonengl          #+#    #+#             */
/*   Updated: 2024/05/24 14:39:42 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clearstack(t_all *meta)
{
	t_stack	*stack_a;
	t_stack *current;
	t_stack	*temp;

	stack_a = meta->stack_a;
	if (!stack_a->next)
	{
		free(stack_a);
		free(meta);
		return ((void)exit);
	}
	current = stack_a->next;

	while (current->pos != 0)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(stack_a);
	free(meta);
}

/*
t_stack	*get_first_element(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return (NULL);
	temp = (*stack);
	while (temp->pos != 1)
		temp = temp->next;
	return (temp);
}

size_t get_stacksize(t_stack **stack)
{
	t_stack	*temp;
	size_t	size;

	if (!stack)
		return (0);
	size = 1;
	temp = get_first_element(stack);
	temp = temp->next;
	while (temp->pos != 1)
		temp = temp->next;
}
*/