/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:22:24 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/20 16:47:56 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

static char	*ft_swap_chars(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++j])
		str[++i] = str[j];
	str[--j] = '\0';
	return (str);
}

static char	*initstr(char *str)
{
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

static char	*address(uintptr_t nb, char *base)
{
	int			i;
	uintptr_t	prod;
	uintptr_t	tmp;
	char		*result;

	prod = 16;
	i = 2;
	tmp = nb;
	while (tmp > 0)
	{
		tmp = tmp / prod;
		i++;
	}
	if (!(result = ft_strnew(i)))
		return (NULL);
	result = initstr(result);
	result[i] = '\0';
	while (--i >= 2)
	{
		result[i] = base[nb % prod];
		nb = nb / prod;
	}
	if (result[++i] == '0' && nb != 0)
		result = ft_swap_chars(result);
	return (result);
}

int		void_param(va_list param, t_data *data, const char *ptr)
{
	char *result;

	result = address(va_arg(param, uintptr_t), BASE_H);
	print_str(result, data, ptr);
	return (0);
}