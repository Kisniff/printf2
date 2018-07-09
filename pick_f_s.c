/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_f_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehideu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:08:46 by jlehideu          #+#    #+#             */
/*   Updated: 2018/07/09 18:16:58 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//precision -> taille minimum a afficher
//minus
//zero
//width

#include "ft_printf.h"
#include <stdio.h>

static int	pick_f_s_2(char *str, t_data *data)
{
	int	i;

	i = -1;
	if (data->width > 0)
	{
		//printf("C\n");
		f_width(data);
		while (++i < data->len)
			fill_buff_c(data, str[i]);
	}
	else
	{
		//printf("ELSE\n");
		while (++i < data->len)
			fill_buff_c(data, str[i]);
	}
	return (0);
}

int	pick_f_s(va_list param, t_data *data, char *ptr)
{
	char	*str; 
	int		i;
	
	i = -1;
	str = va_arg(param, char*);
	if (!str)
	{
		print_str("(null)\0", data, ptr);
		return (0);
	}
	//printf("data->precision %d\n", data->precision);
	data->len = (data->precision < 0) ? 0 : ft_strlen(str);
	data->len = (data->precision > 0 && data->precision < data->len) ? data->precision : data->len;
	//printf("str -> %s\n", str);
	data->precision = 0;
	//printf("data->len = %zu\n", data->len);
	if (data->flags[MINUS])
	{
		//printf("A\n");
		while (++i < data->len)
			fill_buff_c(data, str[i]);
		f_width(data);
	}
	else if (data->flags[ZERO])
	{
		//printf("B\n");
		f_zero(data);
		while (++i < data->len)
			fill_buff_c(data, str[i]);
	}
	else
		pick_f_s_2(str, data);
	return (0);
}
