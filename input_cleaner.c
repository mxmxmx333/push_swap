/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_cleaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:00:43 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/23 18:02:00 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sortingneeded(t_all *meta)
{
	t_clean_input	*temp;
	int				x;

	temp = meta->input;
	while (temp)
	{
		x = temp->number;
		if (!temp->next)
			return (0);
		temp = temp->next;
		if (temp->number < x)
			return (1);
	}
	return (0);
}

int	is_zero_iteration(char *input)
{
	int	i;

	i = 0;
	if (input[i] == '+')
		i++;
	else if (input[i] == '-')
		i++;
	while (input[i] == '0')
		i++;
	return (!input[i]);
}

int	cleansize(char *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (input[i] == '+')
		i++;
	if (input[i] == '-')
	{
		j++;
		i++;
	}
	while (input[i] == '0')
		i++;
	while (input[i++])
		j++;
	return (j);
}

char	*cleanoneinput(char *input)
{
	int		i;
	int		j;
	char	*clean;

	if (is_zero_iteration(input))
		return (ft_strdup("0"));
	j = cleansize(input);
	clean = (char *)malloc(sizeof(char) * (j + 1));
	if (!clean)
		return (NULL);
	j = 0;
	i = 0;
	if (input[i] == '+')
		i++;
	if (input[i] == '-')
	{
		clean[j++] = '-';
		i++;
	}
	while (input[i] == '0')
		i++;
	while (input[i])
		clean[j++] = input[i++];
	clean[j] = '\0';
	return (clean);
}

void	cleaninput(t_all *meta)
{
	t_clean_input	*temp;

	temp = meta->input;
	while (temp)
	{
		temp->clean = cleanoneinput(temp->raw);
		if (!temp->clean)
			return (free_meta(meta), error());
		temp = temp->next;
	}
}
