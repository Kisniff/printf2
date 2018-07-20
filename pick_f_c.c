/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_f_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehideu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:08:58 by jlehideu          #+#    #+#             */
/*   Updated: 2018/07/20 12:01:17 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	pick_f_c(va_list param, t_data *data)
{
	char	result;

	result = va_arg(param, int);
	data->len = 1;
	data->precision = 0;
	if (data->flags[MINUS])
	{
		print_char(result, data);
		f_width(data);
	}
	else if (data->flags[ZERO])
	{
		f_zero(data);
		print_char(result, data);
	}
	else if (data->width)
	{
		f_width(data);
		print_char(result, data);
	}
	else
		print_char(result, data);
	return (0);
}
