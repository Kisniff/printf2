#include "ft_printf.h"
#include <stdio.h>

void	ft_put_u(unsigned int nb, t_data *data)
{
	if (nb / 10)
		ft_put_u(nb / 10, data);
	fill_buff_c(data, nb % 10 + 48);
}

size_t	len_u(unsigned int nb)
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

uintmax_t	retrieve_u_param(t_data *data, va_list param)
{
	if (data->length[H] > 0)
	{
		printf("h\n");
		return (va_arg(param, int));
	}
	else if (data->length[L] == 1)
	{
		printf("l\n");
		return (va_arg(param, unsigned long));
	}
	else if (data->length[L] == 2)
	{
		printf("ll\n");
		return (va_arg(param, unsigned long long));
	}
	else if (data->length[J] == 1)
	{
		printf("j\n");
		return (va_arg(param, uintmax_t));
	}
	else if (data->length[Z] == 1)
	{
		printf("z\n");
		return (va_arg(param, size_t));
	}
	printf("ELSE \n");
	return (va_arg(param, unsigned int));
}

int	pick_f_u(va_list param, t_data *data)
{
	uintmax_t	nb;

	nb = retrieve_u_param(data, param);;
	printf("nombre -> %ju\n", nb);
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
