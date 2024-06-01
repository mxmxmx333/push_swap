/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:21:00 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/01 13:22:24 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

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

int	main(int argc, char **argv)
{
	t_all	*meta;
	
	meta = malloc(sizeof(t_all));
	if (!meta)
		return (free(meta),1);
	meta->stack_a = NULL;
	meta->stack_b = NULL;
	meta->ssa = 0;
	meta->ssb = 0;
	if (argc < 2)
	{
		write(2, "Enter at least 2 arguments. They have to be integers!\n", 55);
		return (free(meta), 1);
	}
	else
	{
		/*CHECK INPUT*/
		fill_stack_a(argc, argv, meta);
		create_stack_b(meta);
		if (is_filled_a(meta))
		{
			
			test_stack(meta);
			printf("------ stack a filled ------\n");
			// pb(meta);
			// printf("------ pb ------\n");
			// rra(meta);
			// test_stack(meta);
			// printf("------ rr a ------\n");
			// rra(meta);
			// test_stack(meta);
			// printf("------ rr a ------\n");
			// rra(meta);
			// test_stack(meta);
			// printf("------ rr a ------\n");

			ra(meta);
			test_stack(meta);
			printf("------ stack a rotated ------\n");
			
			rra(meta);
			test_stack(meta);
			printf("------ stack a r. rotated ------\n");

			pa(meta);
			test_stack(meta);
			printf("------ pushed from empty stack ------\n");

			pb(meta);
			pb(meta);
			pb(meta);
			pb(meta);
			pb(meta);
			test_stack(meta);
			printf("------ pushed pb thrice ------\n");

			rr(meta);
			test_stack(meta);
			printf("------ rotated both stacks ------\n");

			rrr(meta);
			test_stack(meta);
			printf("------ r. rotated both stacks ------\n");
	
			ss(meta);
			test_stack(meta);
			printf("------ ss ------\n");

				
			ss(meta);
			test_stack(meta);
			printf("------ ss ------\n");
			
			get_all_targets_a(meta);
			test_stack(meta);
			printf("------ targeting a ------\n");
			
			getcosts_a(meta);
			test_stack(meta);
			printf("------ calculating costs------\n");
			free_meta(meta);
		}
	}
	return (0);
}
