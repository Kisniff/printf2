#include "ft_printf.h"
#include <stdio.h>

static int	exception_bigs(t_data *data, char *str)
{
	int		i;
	int		len;

	i = -1;
	//printf("Exception\n");
	data->len = (data->precision > 0) ? data->precision : 6;
	data->len = (data->precision < 0) ? 0 : data->len;
	len = data->len;
	if (data->flags[MINUS])
	{
		//printf("A\n");
		while (str[++i] && --len >= 0)
			fill_buff_c(data, str[i]);
		//printf("data->len - %d\n", data->len);
		//printf("data->width- %d\n", data->width);
		f_width_s(data);
	}
	else if (data->flags[ZERO])
	{
		//printf("B\n");
		f_zero_s(data);
		while (str[++i] && --len >= 0)
			fill_buff_c(data, str[i]);
	}
	else if (data->width > 0)
	{
		//printf("C\n");
		f_width_s(data);
		while (str[++i] && --len >= 0)
			fill_buff_c(data, str[i]);
	}
	else
	{
		//printf("D\n");
		while (str[++i] && --len >= 0)
			fill_buff_c(data, str[i]);
	}
	return (0);
}

void		determine_ws_len(t_data *data, wchar_t *str)
{
	int	len_t;
	int	len;
	int	i;

	len_t = 0;
	i = -1;
	len = data->precision;
	data->len = 0;
	while (str[++i] && len > 0)
	{
		if (data->precision > 0)
		{
			if (str[i] < 129 || (str[i] <= 255 && MB_CUR_MAX == 1))
			{
				--len;
				data->len += (len >= 0) ? 1 : 0;
			}
			else if (str[i] < 2049)
			{
				len -= 2;
				data->len += (len >= 0) ? 2 : 0;
			}
			else if (str[i] < 65536)
			{
				len -= 3;
				data->len += (len >= 0) ? 3 : 0;
			}
			else if (str[i] < 2097152)
			{
				len -= 4;
				data->len += (len >= 0) ? 4 : 0;
			}
		}
	}
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
			{
				--len;
			}
			else if (str[i] < 2049)
			{
				len -= 2;
			}
			else if (str[i] < 65536)
			{
				len -= 3;
			}
			else if (str[i] < 2097152)
			{
				len -= 4;
			}
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
	if (data->precision > 0)
		determine_ws_len(data, str);
	//printf("data->len %zu\n", data->len);
	data->len = (data->precision < 0 ) ? 0 : data->len;
	//printf("data->len %zu\n", data->len);
//	if (data->len > data->precision)
//		data->width += data->len - data->precision;
	//data->len = (data->precision > 0 && data->precision < data->len) ? data->precision : data->len;
	//printf("data->flags[ZERO] - %d\n", data->flags[ZERO]);
	if (data->flags[MINUS])
	{
		//printf("A\n");
		write_bigs(data, str);
		//printf("data->len %zu\n", data->len);
		//printf("data->width %d\n", data->width);
		f_width_s(data);
	}
	else if (data->flags[ZERO])
	{
		//printf("B\n");
		f_zero_s(data);
		write_bigs(data, str);
	}
	else 
	{
		//printf("C\n");
		//printf("data->width %d\n", data->width);
		//printf("data->len %zu\n", data->len);
		//printf("data->precision %d\n", data->precision);
		f_width_s(data);
		write_bigs(data, str);
	}
	return (0);
}
