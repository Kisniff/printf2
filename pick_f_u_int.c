/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_f_u_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehideu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:33:48 by jlehideu          #+#    #+#             */
/*   Updated: 2018/06/29 12:52:06 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_put_u(uintmax_t nb, t_data *data)
{
	if (nb / 10)
		ft_put_u(nb / 10, data);
	fill_buff_c(data, nb % 10 + 48);
}

static size_t	len_u(uintmax_t nb)
{
	size_t		len;
	long int	prod;

	len = 0;
	prod = 1;
	if (nb == 0)
		return (1);
	while (nb / prod >= 1)
	{
		prod *= 10;
		++len;
	}
	return (len);
}

static int			exception_zero_u(t_data *data)
{
	data->len = 0;
	if (data->precision == 0 && data->width == 0)
		return (fill_buff_c(data, ""));
	if (data->precision < 0)
	{
		//printf("a\n");
		f_width(data);
		return (0);
	}
	if (data->precision > 0)
	{
		//printf("b\n");
		f_width(data);
		f_precision(data);
	}
	else if (data->flags[ZERO])
	{
		//printf("c\n");
		f_width(data);
		f_zero(data);
	}
	else if (data->width > 0)
	{
		//printf("d\n");
		f_width(data);
	}
	else
	{
		//printf("e\n");
		return (fill_buff_c(data, '0'));
	}
	return (1);
}

static uintmax_t	retrieve_u_param(t_data *data, va_list param)
{
	if (data->length[L] == 1)
		return (va_arg(param, unsigned long));
	else if (data->length[L] == 2)
		return (va_arg(param, unsigned long long));
	else if (data->length[H] > 0)
		return (va_arg(param, int));
	else if (data->length[J] == 1)
		return (va_arg(param, uintmax_t));
	else if (data->length[Z] == 1)
		return (va_arg(param, size_t));
	return (va_arg(param, unsigned int));
}

int	pick_f_u(va_list param, t_data *data, const char *ptr)
{
	uintmax_t	nb;

	nb = retrieve_u_param(data, param);;
	data->len = len_u(nb);
	//printf("data->len %d\nnb -> %zu\n", data->len, nb);
	if (data->len == 1 && nb == 0)
	{
		//printf("exception\n");
		return (exception_zero_u(data));
	}
	data->precision = (data->precision > data->len) ? data->precision - data->len : 0;
	if (data->flags[MINUS])
	{	
		f_precision(data);
		ft_put_u(nb, data);
		f_width(data);
	}
	else if (data->precision > 0 && data->width > 0)
	{
		f_width(data);
		f_precision(data);
		ft_put_u(nb, data);
	}
	else if (data->precision > 0)
	{
		f_width(data);
		f_precision(data);
		ft_put_u(nb, data);
	}
	else if (data->flags[ZERO])
	{ 
		f_zero(data);
		ft_put_u(nb, data);
	}
	else if (data->width > 0)
	{
		f_width(data);
		ft_put_u(nb, data);
	}
	else
		ft_put_u(nb, data);
	return (0);
}
