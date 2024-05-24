/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:49:38 by mbonengl          #+#    #+#             */
/*   Updated: 2024/05/24 14:36:11 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int number, size_t pos)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->number = number;
	new_node->pos = pos;
	new_node->cost = 0;
	new_node->target = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	fill_stack_a(size_t argc, char **argv, t_all *meta)
{
	size_t	pos;
	t_stack	*stack_a;
	t_stack *temp;
	t_stack	*new_node;
	
	stack_a = create_node(0, 0);
	
	if (!stack_a)
		return (clearstack(meta), (void)exit);
	meta->stack_a = stack_a;
	pos = 1;
	temp = stack_a;
	while (pos < argc)
	{
		new_node = create_node(ft_atoi(argv[pos]), pos);
		if (!new_node)
			return  (clearstack(meta), (void)exit);
		temp->next = new_node;
		new_node->prev = temp;
		temp = temp->next;
		pos++;
	}
	temp->next = stack_a;
	stack_a->prev = temp;
}

