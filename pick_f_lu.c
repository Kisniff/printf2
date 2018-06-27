#include "ft_printf.h"
#include <stdio.h>

void	ft_put_u(unsigned long nb, t_data *data)
{
	if (nb / 10)
		ft_put_u(nb / 10, data);
	fill_buff_c(data, nb % 10 + 48);
}

size_t	len_u(unsigned long nb)
{
	size_t		len;
	long int	prod;

	len = 0;
	prod = 1;
	while (nb / prod >= 1)
	{
		prod *= 10;
		++len;
	}
	return (len);
}

int	pick_f_lu(va_list param, t_data *data)
{
	unsigned int	nb;

	nb = va_arg(param, long int);
	data->len = len_u(nb);
	data->precision = (data->precision > data->len) ? data->precision - data->len : 0;
	if (data->flags[MINUS])
	{	
		f_precision(data);
		ft_put_u(nb, data);
		f_width(data);
	}
	else if (data->precision > 0 && data->width > 0)
	{
		f_width(data);
		f_precision(data);
		ft_put_u(nb, data);
	}
	else if (data->precision > 0)
	{
		f_width(data);
		f_precision(data);
		ft_put_u(nb, data);
	}
	else if (data->flags[ZERO])
	{ 
		f_zero(data);
		ft_put_u(nb, data);
	}
	else if (data->width > 0)
	{
		f_width(data);
		ft_put_u(nb, data);
	}
	else
		ft_put_u(nb, data);
	return (0);
}
