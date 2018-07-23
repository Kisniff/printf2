/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:22:24 by sklepper          #+#    #+#             */
/*   Updated: 2018/07/23 15:00:25 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (!(result = ft_strnew((size_t)i)))
		return (NULL);
	while (--i >= 0)
	{
		result[i] = base[nb % prod];
		nb = nb / prod;
	}
	return (result);
}

static char	*add_char(char *str, char *result, int precision)
{
	int i;
	int j;
	int l;

	l = (int)ft_strlen(result);
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
	str[i] = '\0';
	return (str);
}

static char	*manipulation(uintptr_t nb, t_data *data, char *str)
{
	char *result;

	result = address(nb, BASE_H);
	if (data->precision > 0 && (intmax_t)ft_strlen(result) < (data->precision))
	{
		if (!(str = ft_strnew((size_t)data->precision + 2)))
			return (NULL);

	}
	else
		if (!(str = ft_strnew(ft_strlen(result + 2))))
			return (NULL);
	str = initstr(str);
	if (nb > 0 || data->precision != 0)
		str = add_char(str, result, (int)data->precision + 2);
	else if (data->width > 0 && data->flags[ZERO] == 1)
		str = add_char(str, result, data->width);
	data->len = ft_strlen(str);
	if (data->width > 0 && data->flags[MINUS] == 0)
		f_width_p(data, nb);
	if (data->precision == -1 && nb == 0)
		data->len = 2;
	ft_strdel(&result);
	return (str);
}

int		pick_f_p(va_list param, t_data *data, const char *ptr)
{
	char *str;
	uintptr_t nb;

	nb = va_arg(param, uintptr_t);
	str = manipulation(nb, data, str);
	print_str(str, data, "s");
	if (nb == 0 && data->precision == 0 && (data->width == 0 || data->flags[ZERO] == 0))
		print_str("0", data, ptr);
	if (data->flags[MINUS] == 1)
		f_width_p(data, nb);
	ft_strdel(&str);
	return (0);
}
