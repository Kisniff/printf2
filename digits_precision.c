/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 14:57:36 by sklepper          #+#    #+#             */
/*   Updated: 2018/07/16 15:02:35 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	f_precision(t_data *data)
{
	int	precision;

	precision = data->precision;
	if (precision > 0)
		while (--precision >= 0)
			fill_buff_c(data, '0');
	return (0);
}

int	f_zero(t_data *data)
{
	int	zero;
	int	precision;

	precision = (data->precision > 0) ? data->precision : 0;
	zero = (int)(data->width - (data->len + precision));
	if (zero > 0)
		while(--zero >= 0)
			fill_buff_c(data, '0');
	return (0);
}

int	f_width(t_data *data)
{
	int	width;
	int	precision;

	precision = (data->precision > 0) ? data->precision : 0;
	width = (int)(data->width - (data->len + precision + data ->sign));
	if (width > 0)
		while (--width >= 0)
			fill_buff_c(data, ' ');
	return (0);
}

int	f_width_p(t_data *data)
{
	int	width;

	width = (int)(data->width - data->len);
	if (width > 0)
		while (--width >= 0)
			fill_buff_c(data, ' ');
	return (0);
}