/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 16:01:47 by sklepper          #+#    #+#             */
/*   Updated: 2018/07/14 17:52:35 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		path(char *ptr, va_list param, t_data *data)
{
	int i;

	i = 0;
	if ((i = flags(ptr, data)) > 0)
		return (i);
	else if ((i = length(ptr, data)) > 0)
		return (i);
	else if ((i = width(ptr, data)) > 0)
		return (i);
	else
		conversion(ptr, param, data);
	return (0);
}

int		width(char *ptr, t_data *data)
{
	if (*ptr == '.')
		return (precision(ptr + 1, data) + 1);
	else if (*ptr > '0' && *ptr <= '9')
		return (width_min(ptr, data));
	return (0);
}

int		flags(const char *ptr, t_data *data)
{
	if (*ptr == '#')
		return (flag_sharp(data));
	else if (*ptr == '0')
		return (flag_zero(data, ptr));
	else if (*ptr == '-')
		return (flag_minus(data));
	else if (*ptr == '+')
		return (flag_plus(data));
	else if (*ptr == ' ')
		return (flag_space(data));
	return (0);
}

int		length(const char *ptr, t_data *data)
{
	if (*ptr == 'h')
		return (length_h(ptr, data));
	else if (*ptr == 'l')
		return (length_l(ptr, data));
	else if (*ptr == 'j')
		return (length_j(data));
	else if (*ptr == 'z')
		return (length_z(data));
	return (0);
}

int		conversion(const char *ptr, va_list param, t_data *data)
{
	if (*ptr == 'S' || (*ptr == 's' && data->length[L] == 1))
	{
		printf("S\n");
		pick_f_bigs(param, data);
	}
	else if (*ptr == 's')
	{
		printf("s\n");
		pick_f_s(param, data);
	}
	else if (*ptr == 'p')
		pick_f_p(param, data, ptr);
	else if (*ptr == 'd' || *ptr == 'i' || *ptr == 'D')
		pick_f_d(param, data);
	else if (*ptr == 'o' || *ptr == 'O')
		pick_f_base(param, data, ptr);
	else if (*ptr == 'u' || *ptr == 'U')
	{
		if (*ptr == 'U')
			data->length[L] = (data->length[L] == 0) ? 1 : data->length[L];
		pick_f_u(param, data);
	}
	else if (*ptr == 'x' || *ptr == 'X')
		pick_f_base(param, data, ptr);
	else if ((*ptr == 'c' && data->length[L] == 1) || *ptr == 'C')
		pick_f_w(data, param);
	else if (*ptr == 'c')
		pick_f_c(param, data);
	else if (*ptr == '%')
		pick_f_percent(param, data);
	return (0);
}
