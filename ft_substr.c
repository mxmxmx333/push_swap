/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:55:30 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/21 18:58:54 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*alloc_zero(void)
{
	char	*ptr;

	ptr = (char *)ft_calloc(1, sizeof(char));
	if (!ptr)
		return (NULL);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (start > (unsigned int)s_len)
		return (alloc_zero());
	if (len > (size_t)ft_strlen((char *)s + start))
		len = (size_t)ft_strlen((char *)s + start);
	substring = (char *)ft_calloc((len + 1), sizeof(char));
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, s + start, len + 1);
	return (substring);
}

/*
int main(void)
{
	char	*ret;

	ret = ft_substr("01234", 4294967294, 0);
	printf("%s\n", ret);
	//printf("%d", ft_strncmp(ret, "", 1));
}
*/