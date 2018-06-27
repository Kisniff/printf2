#include "ft_printf.h"
#include <stdio.h>
//sharp -> nothing happens
//space -> same
//+ -> same
//precision -> same
int	pick_f_percent(va_list param, t_data *data)
{
	unsigned int	nb;

	nb = va_arg(param, unsigned int);
	data->len = 1;
	data->precision = 0;
	if (data->flags[MINUS])
	{	
		print_char('%', data);
		f_width(data);
	}
	else if (data->flags[ZERO])
	{ 
		f_zero(data);
		print_char('%', data);
	}
	else if (data->width > 0)
	{
		f_width(data);
		print_char('%', data);
	}
	else
		print_char('%', data);
	return (0);
}
