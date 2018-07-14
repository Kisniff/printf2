#include "ft_printf.h"
#include <stdio.h>

static int	exception_bigs(t_data *data, char *str)
{
	//printf("Exception\n");
	if (data->flags[MINUS])
	{
		//printf("A\n");
		write_str(data, str);
		f_width(data);
	}
	else if (data->flags[ZERO])
	{
		//printf("B\n");
		f_zero(data);
		write_str(data, str);
	}
	else if (data->width > 0)
	{
		//printf("C\n");
		f_width(data);
		write_str(data, str);
	}
	else
	{
		//printf("D\n");
		write_str(data, str);
	}
	return (0);
}

static int	write_bigs(t_data *data, wchar_t *str)
{
	int	i;
	int	len;

	i = -1;
	if (!str)
		return (0);
	len = (data->precision > 0) ? data->precision : data->len;
	//printf("data->precision %d\n", data->precision);
	while (str[++i] && len > 0)
	{
		if (data->precision > 0)
		{
			if (str[i] < 129 || (str[i] <= 255 && MB_CUR_MAX == 1))
				--len;
			else if (str[i] < 2049)
				len -= 2;
			else if (str[i] < 65536)
				len -= 3;
			else if (str[i] < 2097152)
				len -= 4;
			//printf("len %d\n", len);
		}
		if (len >= 0)
		{
			if (MB_CUR_MAX == 1 && str[i] <= 255)
			{
				//printf("except locale\n");
				fill_buff_c(data, str[i]);
			}
			else if (MB_CUR_MAX == 1 || str[i] > 1114111 || str[i] < 0 ||(str[i] >= 55295 && str[i] <= 57343))
			{
				//printf("error\n");
				return (data->ret_val = -1);
			}
			else
			{
				//printf("regular\n");
				write_w(data, str[i]);
			}
		}
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
	//printf("data->len %zu\n", data->len);
	data->len = (data->precision < 0 ) ? 0 : data->len;
	data->len = (data->precision > 0 && data->precision < data->len) ? data->precision : data->len;
	//printf("data->len %zu\n", data->len);
	if (data->flags[MINUS])
	{
		//printf("A\n");
		write_bigs(data, str);
		//printf("data->len %zu\n", data->len);
		f_width(data);
	}
	else if (data->flags[ZERO])
	{
		//printf("B\n");
		f_zero(data);
		write_bigs(data, str);
	}
	else 
	{
		//printf("C\n");
		//printf("data->width %d\n", data->width);
		//printf("data->len %zu\n", data->len);
		//printf("data->precision%d\n", data->precision);
		f_width(data);
		write_bigs(data, str);
	}
	return (0);
}
