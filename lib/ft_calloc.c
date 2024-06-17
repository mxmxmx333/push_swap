/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:05:51 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/17 18:26:16 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*pointer;

	if (size && nmemb > SIZE_MAX / size)
		return (0);
	pointer = (void *)malloc(nmemb * size);
	if (!pointer)
		return (NULL);
	ft_bzero((void *)pointer, size * nmemb);
	return (pointer);
}
