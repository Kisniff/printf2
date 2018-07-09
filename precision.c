/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 15:13:50 by sklepper          #+#    #+#             */
/*   Updated: 2018/07/09 18:04:40 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		precision(const char *ptr, t_data *data)
{
	int i;

	i = 0;
	while (*(ptr + i) >= '0' && *(ptr + i) <= '9')
		i++;
	if ((i == 1 && *ptr == '0'))
		data->precision = -1;
	else if (i > 0)
		data->precision = ft_atoi(ptr);
	else 
		data->precision = -1;
	data->flags[ZERO] = 0;
	return (i);
}

int		width_min(const char *ptr, t_data *data)
{
	int i;

	i = 0;
	while (*(ptr + i) >= '0' && *(ptr + i) <= '9')
		i++;
	if (i > 0)
		data->width = ft_atoi(ptr);
	return (i);
}
