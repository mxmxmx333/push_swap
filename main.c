/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:21:00 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/21 18:57:53 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

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
		return (free(meta), 1);
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
		fill_stack_a(meta);
		create_stack_b(meta);
		if (is_filled_a(meta))
		{
			push_swap(meta);
			free_meta(meta);
		}
	}
	return (0);
}
