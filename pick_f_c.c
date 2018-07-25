/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_f_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehideu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:08:58 by jlehideu          #+#    #+#             */
/*   Updated: 2018/07/23 15:43:35 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	pick_f_c(va_list param, t_data *data, char ptr)
{
	char	result;

	if (ptr == 'c')
		result = va_arg(param, int);
	else
		result = ptr;
	data->len = 1;
	data->precision = 0;
	if (data->flags[MINUS])
	{
		fill_buff_c(data, result);
		return (f_width(data));
	}
	else if (data->flags[ZERO])
	{
		f_zero(data);
		return (fill_buff_c(data, result));
	}
	else if (data->width)
	{
		f_width(data);
		return (fill_buff_c(data, result));
	}
	return (fill_buff_c(data, result));
}
