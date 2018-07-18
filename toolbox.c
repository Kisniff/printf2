/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepperstudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:13:31 by sklepper          #+#    #+#             */
/*   Updated: 2018/07/14 17:15:55 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isneg(long long n)
{
	return (n < 0 ? 1 : 0);
}

static size_t	ft_count_nbr(long long n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static long long		ft_nbchar(size_t i, long long nbr)
{
	long long		base;
	long long	n;

	base = 10;
	if (nbr < 0)
		n = -nbr;
	else
		n = nbr;
	if (i == 1)
		base = 1;
	while (i > 2)
	{
		base *= 10;
		i--;
	}
	n = (n / base) % 10;
	return (n);
}

char			*ft_itoa_long(long long n)
{
	size_t	size;
	char	*str;
	int		i;
	long long		nbr;

	i = -1;
	size = 1;
	size += ft_count_nbr(n);
	if ((str = ft_strnew(size)) == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
		str[++i] = '-';
	while (--size != 0)
	{
		nbr = ft_nbchar(size, n);
		str[++i] = (char)(nbr + '0');
	}
	return (str);
}
