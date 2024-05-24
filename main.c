/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:21:00 by mbonengl          #+#    #+#             */
/*   Updated: 2024/05/24 14:36:35 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_stack(t_all *meta)
{
	t_stack *stack_a;
	t_stack	*temp;

	stack_a = meta->stack_a;
	temp = stack_a->next;
	while (temp->pos != 0)
	{
		printf("Pos: %d Number: %d\n", temp->pos, temp->number);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_all	*meta;
	
	meta = malloc(sizeof(t_all));
	if (!meta)
		return (free(meta),1);
	if (argc <= 2)
	{
		write(2, "Enter at least 2 arguments. They have to be integers!\n", 55);
		return (free(meta), 1);
	}
	else
	{
		/*CHECK INPUT*/
		fill_stack_a(argc, argv, meta);
		test_stack(meta);
		clearstack(meta);
	}
	return (0);
}