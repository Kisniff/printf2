/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_f_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:09:15 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/27 10:33:22 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	pick_f_percent(t_data *data)
{
	data->len = 1;
	data->precision = 0;
	if (data->flags[MINUS])
	{
		print_char('%', data);
		f_width(data);
	}
	else if (data->flags[ZERO])
	{
		f_zero(data);
		print_char('%', data);
	}
	else if (data->width > 0)
	{
		f_width(data);
		print_char('%', data);
	}
	else
		print_char('%', data);
	return (0);
}
