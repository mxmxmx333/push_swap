/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:29:16 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/01 13:11:10 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	reindex_b(t_all *meta)
{
	t_stack	*stack_b;
	size_t	pos;

	pos = 1;
	stack_b = meta->stack_b;
	if (!stack_b->next)
		return ;
	while(stack_b->pos != 0)
		stack_b = stack_b->next;
	stack_b = stack_b->next;
	while (stack_b->pos != 0)
	{
		stack_b->pos = pos;
		pos++;
		stack_b = stack_b->next;
	}			
}
void	reindex_a(t_all *meta)
{
	t_stack	*stack_a;
	size_t	pos;

	pos = 1;
	stack_a = meta->stack_a;
	if (!stack_a->next)
		return ;
	while(stack_a->pos != 0)
		stack_a = stack_a->next;
	stack_a = stack_a->next;
	while (stack_a->pos != 0)
	{
		stack_a->pos = pos;
		pos++;
		stack_a = stack_a->next;
	}			
}
void	clearstack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*temp;
	
	if (!stack)
		return ;
	if (!stack->next)
		return (free(stack));
	current = stack->next;
	while (current && current->pos != 0)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(stack);
	stack = NULL;
}

void	free_meta(t_all *meta)
{
	if (!meta)
		return ;
	if (meta->stack_a)
		clearstack(meta->stack_a);
	meta->stack_a = NULL;
	if (meta->stack_b)
		clearstack(meta->stack_b);
	meta->stack_b = NULL;
	free(meta);
	meta = NULL;
}

void	put_direction(t_stack *node, int a, int b)
{
	node->dir_a = a;
	node->dir_b = b;
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