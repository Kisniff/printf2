/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehideu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:55:26 by jlehideu          #+#    #+#             */
/*   Updated: 2018/07/23 15:55:30 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_sharp(t_data *data)
{
	data->flags[SHARP] = 1;
	return (1);
}

int		flag_zero(t_data *data, const char *ptr)
{
	data->flags[ZERO] = 1;
	data->width = ft_atoi((char *)ptr);
	return (1);
}

int		flag_minus(t_data *data)
{
	data->flags[MINUS] = 1;
	return (1);
}

int		flag_plus(t_data *data)
{
	data->flags[PLUS] = 1;
	return (1);
}

int		flag_space(t_data *data)
{
	data->flags[SPACE] = 1;
	return (1);
}
