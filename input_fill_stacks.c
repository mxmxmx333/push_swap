/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_fill_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:49:38 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/21 17:47:23 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_filled_a(t_all *meta)
{
	return (meta->stack_a && meta->stack_a->next);
}
t_stack	*create_node(int number, size_t pos, t_all *meta)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (free_meta(meta), error(), NULL);
	new_node->number = number;
	new_node->pos = pos;
	new_node->cost = 0;
	new_node->dir_a = 0;
	new_node->dir_b = 0;
	new_node->target = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
void	create_stack_b(t_all *meta)
{
	t_stack	*stack_b;
	
	stack_b = create_node(0, 0, meta);
	meta->stack_b = stack_b;
	if (!stack_b)
		return(free_meta(meta), error());
	meta->ssb++;
}
void	fill_stack_a(size_t argc, char **argv, t_all *meta)
{
	size_t			pos;
	t_stack			*stack_a;
	t_stack 		*temp;
	t_stack			*new_node;
	t_clean_input	*input;

	input = meta->input;
	stack_a = create_node(0, 0, meta);
	if (!stack_a)
		return (free_meta(meta), error());
	meta->stack_a = stack_a;
	meta->ssa++;
	pos = 1;
	temp = stack_a;
	while (input)
	{
		new_node = create_node(input->number, pos, meta);
		if (!new_node)
			return  (free_meta(meta), error());
		meta->ssa++;
		temp->next = new_node;
		new_node->prev = temp;
		temp = temp->next;
		pos++;
		input = input->next;
	}
	temp->next = stack_a;
	stack_a->prev = temp;
}

