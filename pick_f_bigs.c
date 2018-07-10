#include "ft_printf.h"
#include <stdio.h>

static int	exception_bigs(t_data *data, char *str)
{
	printf("Exception\n");
	if (data->flags[MINUS])
	{
		printf("A\n");
		write_str(data, str);
		f_width(data);
	}
	else if (data->flags[ZERO])
	{
		printf("B\n");
		f_zero(data);
		write_str(data, str);
	}
	else if (data->width > 0)
	{
		printf("C\n");
		f_width(data);
		write_str(data, str);
	}
	else
	{
		printf("D\n");
		write_str(data, str);
	}
	return (0);
}

static int	write_bigs(t_data *data, wchar_t *str)
{
	int	i;
	int	len;

	i = -1;
	len = data->len;
	if (!str)
		return (0);
	while (str[++i] && len > 0)
	{
		write_w(data, str[i]);
		if (str[i] < 129)
			--len;
		else if (str[i] < 2049)
			len -= 2;
		else if (str[i] < 55295)
			len -= 3;
		else if (str[i] < 2097152)
			len -= 4;
	}
	return (0);
}

int	pick_f_bigs(va_list param, t_data *data)
{
	wchar_t *str;
	int	i;
	
	str = va_arg(param, wchar_t *);
	i = -1;
	if (!str)
		return (exception_bigs(data, "(null)"));
	while (str[++i])
		determine_w_len(data, str[i]);
	data->len = (data->precision < 0 ) ? 0 : data->len;
	data->len = (data->precision > 0 && data->precision < data->len) ? data->precision : data->len;
	if (data->flags[MINUS])
	{
		printf("A\n");
		write_bigs(data, str);
		f_width(data);
	}
	else if (data->flags[ZERO])
	{
		printf("B\n");
		f_zero(data);
		write_bigs(data, str);
	}
	else 
	{
		printf("C\n");
		printf("data->width %d\n", data->width);
		printf("data->len %zu\n", data->len);
		printf("data->precision%d\n", data->precision);
		f_width(data);
		write_bigs(data, str);
	}
	return (0);
}
