/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_f_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehideu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:08:46 by jlehideu          #+#    #+#             */
/*   Updated: 2018/07/10 17:48:13 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//precision -> taille minimum a afficher
//minus
//zero
//width

#include "ft_printf.h"
#include <stdio.h>

int	write_str(t_data *data, char *str)
{
	int	i;

	i = -1;
	while (++i < data->len)
		fill_buff_c(data, str[i]);
	return (0);
}

static int	exception_s(t_data *data)
{
	//printf("exception\n");
	//printf("data->precision %d\n", data->precision);
	data->len = (data->precision < 0) ? 0 : 6;
	data->len = (data->precision > 0 && data->precision < data->len) ? data->precision : data->len;
	//printf("");
	data->precision = 0;
	//printf("data->len %zu\n", data->len);
	//printf("data->width %d\n", data->width);
	if (data->flags[MINUS])
	{
		//printf("A\n");
		write_str(data, "(null)");
		f_width_s(data);
	}
	else if (data->flags[ZERO])
	{
		//printf("B\n");
		f_zero(data);
		write_str(data, "(null)");
	}
	else if (data->width > 0)
	{
		//printf("C\n");
		f_width_s(data);
		write_str(data, "(null)");
	}
	else
	{
		//printf("ELSE\n");
		write_str(data, "(null)");
	}
	return (0);
}

static int	pick_f_s_2(char *str, t_data *data)
{
	int	i;

	i = -1;
	if (data->width > 0)
	{
		//printf("C\n");
		f_width_s(data);
		write_str(data, str);
	}
	else
	{
		//printf("ELSE\n");
		write_str(data, str);
	}
	return (0);
}

int	pick_f_s(va_list param, t_data *data, const char *ptr)
{
	char	*str; 
	int		i;
	
	i = -1;
	str = va_arg(param, char*);
	if (!str)
		return (exception_s(data));
	//printf("data->precision %d\n", data->precision);
	data->len = (data->precision < 0) ? 0 : ft_strlen(str);
	data->len = (data->precision > 0 && data->precision < data->len) ? data->precision : data->len;
	//printf("str -> %s\n", str);
	data->precision = 0;
	//printf("data->len = %zu\n", data->len);
	if (data->flags[MINUS])
	{
		//printf("A\n");
		write_str(data, str);
		f_width_s(data);
	}
	else if (data->flags[ZERO])
	{
		//printf("B\n");
		f_zero(data);
		write_str(data, str);
	}
	else
		pick_f_s_2(str, data);
	return (0);
}
