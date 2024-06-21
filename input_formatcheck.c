/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_formatcheck.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:22:19 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/21 18:22:19 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isplusminus(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	checkformat(char *input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (!ft_isdigit(input[i]) && !isplusminus
			(input[i]) && !ft_isspace(input[i]))
			return (0);
		if (isplusminus(input[i]) && !ft_isdigit(input[i + 1]))
			return (0);
		if (ft_isdigit(input[i]) && isplusminus(input[i + 1]))
			return (0);
	}
	return (1);
}
