/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits_precision_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehideu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 11:58:25 by jlehideu          #+#    #+#             */
/*   Updated: 2018/07/18 17:42:11 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	f_zero_s(t_data *data)
{
	int	zero;

	zero = (int)(data->width - data->len);
	if (zero > 0)
		while (--zero >= 0)
			fill_buff_c(data, '0');
	return (0);
}

int	f_width_s(t_data *data)
{
	int	width;

	width = (int)(data->width - data->len);
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
