/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_convertcheckback.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:37:31 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/21 17:48:14 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	convertnumbers(t_all *meta)
{
	t_clean_input	*current;

	current = meta->input;
	while (current)
	{
		if (!ft_atoi(current->clean, &current->number))
			return (free_meta(meta), error());
		current = current->next;
	}
}

void	checkdupes(t_all *meta)
{
	t_clean_input	*current;
	t_clean_input	*temp;

	current = meta->input;
	while (current)
	{
		temp = current->next;
		while (temp)
		{
			if (current->number == temp->number)
				return (free_meta(meta), error());
			temp = temp->next;
		}
		current = current->next;
	}
}

void convertback(t_all *meta)
{
	t_clean_input	*current;
	int				i;

	current = meta->input;
	while (current)
	{
		current->compare = ft_itoa(current->number);
		if (!current->compare)
			return (free_meta(meta), error());
		if (ft_strcmp(current->clean, current->compare))
			return (free_meta(meta), error());
		current = current->next;
	}
}
