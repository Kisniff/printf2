#include "ft_printf.h"
#include <stdio.h>

int	f_precision(t_data *data)
{
	int	precision;

	precision = data->precision;
	if (precision > 0)
		while (--precision >= 0)
			fill_buff_c(data, '0');
	return (0);
}

int	f_zero(t_data *data)
{
	int	zero;
	int	precision;

	precision = (data->precision > 0) ? data->precision : 0;
	zero = (int)(data->width - (data->len + precision));
	if (zero > 0)
		while(--zero >= 0)
			fill_buff_c(data, '0');
	return (0);
}

int	f_zero_s(t_data *data)
{
	int	zero;
	int	precision;

	zero = (int)(data->width - data->len);
	if (zero > 0)
		while(--zero >= 0)
			fill_buff_c(data, '0');
	return (0);
}

int	f_width(t_data *data)
{
	int	width;
	int	precision;

	//printf("F_WIDTH\n");
	precision = (data->precision > 0) ? data->precision : 0;
	//printf("data->width -> %d\n", data->width);
	width = (int)(data->width - (data->len + precision));
	//printf("width -> %d\n", width);
	//printf("data->precision-> %d\n", data->width);
	if (width > 0)
		while (--width >= 0)
			fill_buff_c(data, ' ');
	return (0);
}

int	f_width_s(t_data *data)
{
	int	width;

	//printf("F_WIDTH_S\n");
	//printf("data->width -> %d\n", data->width);
	width = (int)(data->width - data->len);
	//printf("width -> %d\n", width);
	//printf("data->len-> %d\n", data->len);
	if (width > 0)
		while (--width >= 0)
			fill_buff_c(data, ' ');
	return (0);
}

int	f_width_p(t_data *data)
{
	int	width;
	int	precision;

	width = (int)(data->width - data->len);
	if (width > 0)
		while (--width >= 0)
			fill_buff_c(data, ' ');
	return (0);
}
