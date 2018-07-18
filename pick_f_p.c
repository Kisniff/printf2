/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:22:24 by sklepper          #+#    #+#             */
/*   Updated: 2018/07/18 17:45:43 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	i = 0;
	tmp = nb;
	while (tmp > 0)
	{
		tmp = tmp / prod;
		i++;
	}
	if (i == 0)
		i = 1;
	if (!(result = ft_strnew(i)))
		return (NULL);
	while (--i >= 0)
	{
		result[i] = base[nb % prod];
		nb = nb / prod;
	}
	if (result[++i] == '0' && nb != 0)
		result = ft_swap_chars(result);
	return (result);
}

static char	*add_char(char *str, char *result, int precision)
{
	int i;
	int j;
	int l;

	l = ft_strlen(result);
	i = 2;
	while (i + l < precision)
	{
		str[i] = '0';
		i++;
	}
	j = 0;
	while (result[j])
	{
		str[i] = result[j];
		i++;
		j++;
	}
	return (str);
}

int		pick_f_p(va_list param, t_data *data, const char *ptr)
{
	char *result;
	char *str;
	uintptr_t nb;

	nb = va_arg(param, uintptr_t);
	result = address(nb, BASE_H);
	if (data->precision > -1 && (intmax_t)ft_strlen(result) < (data->precision))
		str = ft_strnew(data->precision + 2);
	else
		str = ft_strnew(ft_strlen(result + 2));
	str = initstr(str);
	if (nb > 0 || data->precision != 0)
		str = add_char(str, result, data->precision + 2);
	data->len = ft_strlen(str);
	if (data->width > 0)
		f_width_p(data);
	print_str(str, data, ptr);
	ft_strdel(&result);
	ft_strdel(&str);
	return (0);
}
