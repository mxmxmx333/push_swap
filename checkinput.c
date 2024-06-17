/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:04:06 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/17 19:25:31 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_clean_input	*create_list(t_all *meta)
{
	t_clean_input	*new;

	new = (t_clean_input *)malloc(sizeof(t_clean_input));
	if (!new)
		return (free_meta(meta), exit(1), NULL);
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
		return (free_meta(meta), exit(1));
	new->raw = ft_strdup(input);
	if (!new->raw)
		return (free_meta(meta), exit(1));
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
		return (free_meta(meta), exit(1));
	meta->split = split;
	while (split[++i])
		appendstring(split[i], meta);
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	meta->split = NULL;
}

int	checkinputs(int argc, char **argv, t_all *meta)
{
	int		i;

	i = -1;
	while (++i < argc)
	{
		if (!checkformat(argv[i]))
			return (0);
	}
	i = -1;
	while (++i < argc)
		appendinput(argv[i], meta);
	cleaninputs(meta);
	convertnumbers(meta);
	convertback(meta);
	if (!compare_input(meta))
		return (0);
	return (1);
}