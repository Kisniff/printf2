/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 14:40:48 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/19 14:23:20 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		length_h(const char *ptr, t_data *data)
{
	data->length[H] = 1;
	if (*(ptr + 1) == 'h')
	{
		data->length[H] = 2;
		return (2);
	}
	return (1);
}

int		length_l(const char *ptr, t_data *data)
{
	data->length[L] = 1;
	if (*(ptr + 1) == 'l')
	{
		data->length[L] = 2;
		return (2);
	}
	return (1);
}

int		length_j(t_data *data)
{
	data->length[J] = 1;
	return (1);
}

int		length_z(t_data *data)
{
	data->length[Z] = 1;
	return (1);
}
