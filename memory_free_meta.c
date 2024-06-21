/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free_meta.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:24:49 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/21 17:27:50 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
void	free_split(t_all *meta)
{
	int	i;

	i = 0;
	char **split;
	
	split = meta->split;
	if (!split)
		return;
	while (split[i])
	{
		ft_free((void **)&split[i]);
		i++;
	}
	ft_free((void **)&split);
}

void clearstack(t_stack *stack)
{
	t_stack *current;
	t_stack *temp;

	if (!stack)
		return;
	if (!stack->next)
		return (ft_free((void **)&stack));
	current = stack->next;
	while (current && current->pos != 0)
	{
		temp = current;
		current = current->next;
		ft_free((void **)&temp);
	}
	ft_free((void **)&stack);
	stack = NULL;
}

void free_meta(t_all *meta)
{
	if (!meta)
		return;
	if (meta->stack_a)
		clearstack(meta->stack_a);
	meta->stack_a = NULL;
	if (meta->stack_b)
		clearstack(meta->stack_b);
	meta->stack_b = NULL;
	if (meta->input)
		clearinput(meta);
	free_split(meta);
	ft_free((void **)&meta);
	meta = NULL;
}

void clearinput(t_all *meta)
{
	t_clean_input *current;
	t_clean_input *temp;

	current = meta->input;
	while (current)
	{
		temp = current;
		current = current->next;
		if (temp->raw)
			ft_free((void **)&temp->raw);
		if (temp->clean)
			ft_free((void **)&temp->clean);
		if (temp->compare)
			ft_free((void **)&temp->compare);
		ft_free((void **)&temp);
	}
	meta->input = NULL;
}
