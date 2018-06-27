// NO SHARP
// NO PRECISION
// NO 0
// MINUS -> blancks on the left
// width -> usual
#include "ft_printf.h"
#include <stdio.h>

int	pick_f_c(va_list param, t_data *data)
{
	char	result;

	result = va_arg(param, int);
	data->len = 1;
	if (data->flags[MINUS])
	{
		print_char(result, data);
		f_width(data);
	}
	else if (data->width)
	{
		f_width(data);
		print_char(result, data);
	}
	else
		print_char(result, data);
	return (0);
}
