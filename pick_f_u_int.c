/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_f_u_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehideu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:33:48 by jlehideu          #+#    #+#             */
/*   Updated: 2018/07/10 15:53:14 by jlehideu         ###   ########.fr       */
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

uintmax_t	len_u(uintmax_t nb)
{
	uintmax_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb >= 1)
	{
		nb = nb / 10;
		++len;
	}
	return (len);
}

static int			exception_zero_u(t_data *data)
{
	data->len = 0;
	if (data->precision == 0 && data->width == 0)
	{
		//printf("all to 0\n");
		return (fill_buff_c(data, '0'));
	}
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
	//printf("retrieve\n");
	if (data->length[L] == 1)
		return (va_arg(param, unsigned long));
	else if (data->length[L] == 2)
	{
		//printf("ll\n");
		return (va_arg(param, unsigned long long));
	}
	else if (data->length[H] == 1)
		return ((unsigned short)va_arg(param, unsigned long));
	else if (data->length[H] == 2)
		return ((unsigned char)va_arg(param, unsigned long));
	else if (data->length[J] == 1)
		return (va_arg(param, uintmax_t));
	else if (data->length[Z] == 1)
		return (va_arg(param, size_t));
	//printf("ELSE\n");
	return (va_arg(param, unsigned int));
}

int	pick_f_u(va_list param, t_data *data, const char *ptr)
{
	uintmax_t	nb;
	int		prec;

	nb = retrieve_u_param(data, param);;
	data->len = len_u(nb);
	//printf("nb -> %u\n", nb);
	//printf("data->len %zu\nnb -> %zu\n", data->len, nb);
	//printf("data->precision -> %d\n", data->precision);
	if (data->len == 1 && nb == 0)
	{
		//printf("exception\n");
		return (exception_zero_u(data));
	}
	prec = data->precision;
	data->precision = (data->precision > data->len) ? data->precision - data->len : 0;
	//printf("data->precision -> %d\n", data->precision);
	if (data->flags[MINUS])
	{	
		//printf("A\n");
		f_precision(data);
		ft_put_u(nb, data);
		f_width(data);
	}
	else if (data->precision > 0)
	{
		//printf("B\n");
		//printf("precision -> %d\n", data->precision);
		f_width(data);
		f_precision(data);
		ft_put_u(nb, data);
	}
	else if (data->flags[ZERO])
	{ 
		//printf("C\n");
		if (prec <= 0)
		{
			//printf("prec -> %d\n", data->precision);
			f_zero(data);
		}
		else
			f_width(data);
		ft_put_u(nb, data);
	}
	else if (data->width > 0)
	{
		//printf("D\n");
		f_width(data);
		ft_put_u(nb, data);
	}
	else
		ft_put_u(nb, data);
	return (0);
}
