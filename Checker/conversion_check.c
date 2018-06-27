/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:15:49 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/20 13:48:28 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		check_s(t_data *data)
{
	if (data->length[H] > 0 || data->length[L] > 1 || data->length[J] > 0 ||
		data->length[Z] > 0)
		return (-1);
	if (data->flags[SHARP] > 0 || data->flags[ZERO] > 0 ||
		data->flags[SPACE] > 0 || data->flags[PLUS] > 0)
		return (-1);
	return (0);
}

int		check_s_c_p(t_data *data)
{
	if (data->length[H] > 0 || data->length[L] > 0 || data->length[J] > 0 ||
		data->length[Z] > 0)
		return (-1);
	if (data->flags[SHARP] > 0 || data->flags[ZERO] > 0 ||
		data->flags[SPACE] > 0 || data->flags[PLUS] > 0)
		return (-1);
	return (0);
}

int		check_di(t_data *data)
{
	if (data->flags[SHARP] > 0)
		return (-1);
	return (0);
}

int		check_ox(t_data *data)
{
	if (data->flags[SPACE] > 0 || data->flags[PLUS] > 0)
		return (-1);
	return (0);
}

int		check_u(t_data *data)
{
	if (data->flags[SHARP] > 0 || data->flags[SPACE] > 0 ||
		data->flags[PLUS] > 0)
		return (-1);
	return (0);
}