/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:21:00 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/21 17:47:35 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
/*
void	test_stack(t_all *meta)
{
	t_stack *stack;
	t_stack	*temp;

	if (meta->stack_a && meta->stack_a->next)
	{
		printf("Stack A:\n");
		stack = meta->stack_a;
		temp = stack->next;
		while (temp->pos != 0)
		{
			printf("Adress: %p Pos: %zu Number: %d Target: %p Cost: %zu dir_a: %d dir_b: %d\n",temp, temp->pos, temp->number, temp->target, temp->cost, temp->dir_a, temp->dir_b);
			temp = temp->next;
		}
	}
	else
		printf("stack a is empty\n");
	if (meta->stack_b && meta->stack_b->next)
	{
		printf("Stack B:\n");
		stack = meta->stack_b;
		temp = stack->next;
		while (temp->pos != 0)
		{
			printf("Adress: %p Pos: %zu Number: %d Target: %p Cost: %zu\n",temp, temp->pos, temp->number, temp->target, temp->cost);
			temp = temp->next;
		}
	}
	else
		printf("stack b is empty\n");
}
*/
void	set_meta_null(t_all *meta)
{
	meta->stack_a = NULL;
	meta->stack_b = NULL;
	meta->input = NULL;
	meta->split = NULL;
	meta->ssa = 0;
	meta->ssb = 0;
}
void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_all	*meta;
	
	meta = malloc(sizeof(t_all));
	if (!meta)
		return (free(meta),1);
	set_meta_null(meta);
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (free(meta), 1);
	}
	else
	{
		if (!checkinputs(argc, argv, meta))
			return (free_meta(meta), exit(1), 1);
		fill_stack_a(argc, argv, meta);
		create_stack_b(meta);
		if (is_filled_a(meta))
		{
			push_swap(meta);
			free_meta(meta);
		}
	}
	return (0);
}
