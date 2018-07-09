/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_f_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehideu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 12:33:50 by jlehideu          #+#    #+#             */
/*   Updated: 2018/07/09 18:13:26 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static int	f_x_sharp(t_data *data, const char *ptr, char *result)
{
	if (data->flags[SHARP] > 0 && *ptr == 'x')
		print_str("0x", data, "z");
	else if (data->flags[SHARP] && *ptr == 'X')
		print_str("0X", data, "z");
	else if (data->flags[SHARP] && (*ptr == 'o' || *ptr == 'O'))
		print_str("0", data, "z");
	return (0);
}

static char	*determine_xo_call(const char *ptr, va_list param, t_data *data)
{
	char		*result;
	uintmax_t	tmp;

	if (data->length[H] == 2)
	{
		//printf("hh\n");
		tmp = (uintmax_t)va_arg(param, unsigned char);
	}
	else if (data->length[H] == 1)
	{
		//printf("h\n");
		tmp = (uintmax_t)va_arg(param, unsigned short);
	}
	else if (data->length[L] == 1)
	{
		//printf("l\n");
		tmp = (uintmax_t)va_arg(param, unsigned long);
	}
	else if (data->length[L] == 2)
	{
		//printf("ll\n");
		tmp = (uintmax_t)va_arg(param, unsigned long long);
	}
	else if (data->length[J] == 1)
	{
		//printf("j\n");
		tmp = va_arg(param, uintmax_t);
	}
	else if (data->length[Z] == 1)
	{
		//printf("z\n");
		tmp = (uintmax_t)va_arg(param, size_t);
	}
	else if (*ptr == 'x' || *ptr == 'X')
	{
		//printf("else x\n");
		tmp = va_arg(param, unsigned int);
		if (tmp > 4294967295)
			tmp = (4294967296 - tmp) * -1;
	}
	else if (*ptr == 'o')
	{
		//printf("else o\n");
		tmp = va_arg(param, unsigned int);
	}
	else if (*ptr == 'O')
	{
		//printf("else O\n");
		tmp = va_arg(param, uintmax_t);
	}
	if (*ptr == 'x')
		result = to_base(tmp, BASE_H);
	else if (*ptr == 'X')
		result = to_base(tmp, BASE_HC);
	else if (*ptr == 'o' || *ptr == 'O')
		result = to_base(tmp, BASE_O);
	return (result);
}

static int	exception_zero_x(char *result, t_data *data, const char *ptr)
{
	data->len = 0;
	//printf("EXCEPTION \n");
	//printf("data->precision EO -> %d\n", data->precision);
	//printf("data->widthEO -> %d\n", data->width);
	//printf("data-> sharp EO -> %d\n", data->flags[SHARP]);
	data->flags[SHARP] = (data->flags[ZERO] > 0) ? 0 : data->flags[SHARP];
	if (data->precision == 0 && data->width <= 1 && data->flags[SHARP] == 0)
		return (fill_buff_c(data, '0'));
	if (data->precision <= 0 && (*ptr == 'o' || *ptr == 'O'))
		data->precision = (data->flags[SHARP] > 0) ? 1 : -1;
	if (data->flags[MINUS] > 0)
	{
		//printf("a\n");
		f_precision(data);
		f_width(data);
		return (0);
	}
	else if (data->precision > 0)
	{
		//printf("b\n");
		f_width(data);
		f_precision(data);
	}
	else if (data->flags[ZERO])
	{
		//printf("c\n");
		f_zero(data);
	}
	else if (data->width > 0)
	{
		//printf("d\n");
		f_width(data);
	}
	else if (data->precision >= 0)
	{
		//printf("e\n");
		return (fill_buff_c(data, '0'));
	}
	//printf("ELSE\n");
	return (1);
}


int	pick_f_x_two(char *result, t_data *data, const char *ptr)
{
	if (data->flags[ZERO])
	{
		//printf("C\n");
		f_x_sharp(data, ptr, result);
		f_zero(data);
		print_str(result, data, "z");
	}
	else if (data->width > 0)
	{
		//printf("D\n");
		f_width(data);
		f_x_sharp(data, ptr, result);
		print_str(result, data, "z");
	}
	else
	{
		//printf("E\n");
		//printf("0 buff -> %s\n", data->buff);
		f_x_sharp(data, ptr, result);
		//printf("1 buff -> %s\n", data->buff);
		print_str(result, data, "z");
		//printf("2 buff -> %s\n", data->buff);
	}
	return (0);
}

int	pick_f_base(va_list param, t_data *data, const char *ptr)
{
	//comportement indéfini precision et largeur = int max
	char	*result;

	result = determine_xo_call(ptr, param, data);
	//printf("result -> %s\n", result);
	data->len = (result != NULL) ? ft_strlen(result) : 0;
	//printf("data->len-> %zu\n", data->len);
	if (data->len == 1 && *result == '0')
		return(exception_zero_x(result, data, ptr));
	data->width = (data->flags[SHARP] && (*ptr == 'x' || *ptr == 'X')) ? data->width - 2 : data->width;
	data->len = (data->flags[SHARP] && (*ptr == 'o' || *ptr == 'O')) ? ++data->len : data->len;
	//printf("1 data->precision-> %d\n", data->precision);
	if (data->precision >= 0)
		data->precision = (data->precision > data->len) ? data->precision - data->len : 0;
	//printf("2 data->precision-> %d\n", data->precision);
	if (data->flags[MINUS])
	{
		//printf("A\n");
		f_x_sharp(data, ptr, result);
		f_precision(data);
		print_str(result, data, "z");
		f_width(data);
	}
	else if (data->precision > 0)
	{
		//printf("B\n");
		f_width(data);
		f_x_sharp(data, ptr, result);
		f_precision(data);
		print_str(result, data, "z");
	}
	else (pick_f_x_two(result, data, ptr));
	free(result);
	return (0);
}
