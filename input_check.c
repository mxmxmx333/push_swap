/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:04:06 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/21 17:46:37 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_clean_input	*create_list(t_all *meta)
{
	t_clean_input	*new;

	new = (t_clean_input *)malloc(sizeof(t_clean_input));
	if (!new)
		return (free_meta(meta), error(), NULL);
	new->raw = NULL;
	new->clean = NULL;
	new->compare = NULL;
	new->next = NULL;
	return (new);
}

void	add_to_end(t_all *meta, t_clean_input *new)
{
	t_clean_input	*temp;

	temp = meta->input;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	appendstring(char *input, t_all *meta)
{
	t_clean_input	*new;

	new = create_list(meta);
	if (!new)
		return (free_meta(meta), error());
	new->raw = ft_strdup(input);
	if (!new->raw)
		return (free(new), free_meta(meta), error());
	if (!meta->input)
		meta->input = new;
	else
		add_to_end(meta, new);
}
void	appendinput(char *input, t_all *meta)
{
	char	**split;
	int		i;

	i = -1;
	split = ft_split(input, ' ');
	if (!split)
		return (free_meta(meta), error());
	meta->split = split;
	while (split[++i])
		appendstring(split[i], meta);
	i = -1;
	while (split[++i])
		ft_free((void **)&split[i]);
	ft_free((void **)&split);
	meta->split = NULL;
}

int	checkinputs(int argc, char **argv, t_all *meta)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (!checkformat(argv[i]))
			return (free_meta(meta), error(), 0);
	}
	i = 0;
	while (++i < argc)
		appendinput(argv[i], meta);
	cleaninput(meta);
	convertnumbers(meta);
	checkdupes(meta);
	convertback(meta);
	return (1);
}
