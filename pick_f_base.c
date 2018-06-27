#include <stdio.h>
#include "ft_printf.h"

int	f_x_sharp(t_data *data, const char *ptr)
{
	if (data->flags[SHARP] > 0 && *ptr == 'x')
		print_str("0x", data);
	else if (data->flags[SHARP] && *ptr == 'X')
		print_str("0X", data);
	return (0);
}

int	pick_f_x_two(char *result, t_data *data, const char *ptr)
{
	if (data->precision > 0)
	{
		f_width(data);
		f_x_sharp(data, ptr);
		f_precision(data);
		print_str(result, data);
	}
	else if (data->flags[ZERO])
	{
		f_x_sharp(data, ptr);
		f_zero(data);
		print_str(result, data);
	}
	else if (data->width > 0)
	{
		
		f_width(data);
		f_x_sharp(data, ptr);
		print_str(result, data);
	}
	else
	{
		f_x_sharp(data, ptr);
		print_str(result, data);
	}
	return (0);
}

char	*determine_xo_call(const char *ptr, va_list param, t_data *data)
{
	char		*result;
	uintmax_t	tmp;

	if (data->length[H] > 0)
		tmp = (uintmax_t)va_arg(param, int);
	else if (data->length[L] == 1)
		tmp = (uintmax_t)va_arg(param, unsigned long);
	else if (data->length[L] == 2)
		tmp = (uintmax_t)va_arg(param, unsigned long long);
	else if (data->length[J] == 1)
		tmp = va_arg(param, uintmax_t);
	else if (data->length[Z] == 1)
		tmp = (uintmax_t)va_arg(param, size_t);
	else
	{
		tmp = va_arg(param, unsigned long);
		if (tmp > 4294967295)
			tmp = (4294967296 - tmp) * -1;
	}
	if (*ptr == 'x')
		result = to_base(tmp, BASE_H);
	else if (*ptr == 'X')
		result = to_base(tmp, BASE_HC);
	else if (*ptr == 'o')
		result = to_base(tmp, BASE_O);
	return (result);
}

int	pick_f_base(va_list param, t_data *data, const char *ptr)
{
	//comportement indéfini precision et largeur = int max
	char	*result;

	result = determine_xo_call(ptr, param, data);
	data->len = ft_strlen(result);
	if (data->len == 1 && *result == '0' && data->precision == 1)
		return (fill_buff_c(data, '0'));
	data->len = (data->flags[SHARP] && (*ptr == 'x' || *ptr == 'X')) ? data->len + 2 : data->len;
	data->len = (data->flags[SHARP] && (*ptr == 'o' || *ptr == 'O')) ? ++data->len : data->len;
	data->precision = (data->precision > data->len) ? data->precision - (data->len) : 0;
	if (data->flags[MINUS])
	{
		f_x_sharp(data, ptr);
		f_precision(data);
		print_str(result, data);
		f_width(data);
	}
	else if (data->precision > 0 && data->width > 0)
	{
		f_width(data);
		f_x_sharp(data, ptr);
		f_precision(data);
		print_str(result, data);
	}
	else (pick_f_x_two(result, data, ptr));
	free(result);
	return (0);
}
