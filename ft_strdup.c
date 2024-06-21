/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:41:07 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/18 20:07:40 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	int		strlen;
	int		i;
	char	*duplicate;

	strlen = ft_strlen((char *)s);
	duplicate = (char *)ft_calloc(strlen + 1, sizeof(char));
	if (!duplicate)
		return (NULL);
	i = 0;
	while (*s)
	{
		duplicate[i] = *s;
		s++;
		i++;
	}
	duplicate[i] = 0;
	return (duplicate);
}
/* cannot be protected, is supposed to crash*/