/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:19:30 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/19 11:57:55 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

static int	checkoverflow(long res, int num, int sign)
{
	if (sign == 1)
	{
		if (res > (LONG_MAX - num) / 10)
			return (-1);
	}
	else
	{
		if (-res < (LONG_MIN + num) / 10)
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *nptr, int *nbr)
{
	int		sign;
	long	res;
	int		of;

	res = 0;
	sign = 1;
	while ((*nptr > 8 && *nptr < 14) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9' && *nptr)
	{
		of = checkoverflow(res, *nptr - '0', sign);
		if (of != 1)
			return (0);
		res = res * 10 + *nptr - 48;
		nptr++;
	}
	*nbr = (int)res * sign;
	return (1);
}

/*
//this function should crash for NULL input
int main (void)
{
	printf("atoi: %d\n", atoi("\t\v\f\r\n -21474836481234341"));
	printf("ft_atoi: %d\n", ft_atoi("\t\v\f\r\n -21474836481234341"));
}
*/