#include "ft_printf.h"
#include <stdio.h>

void	write_quadruple(wchar_t unicode, t_data *data)
{
	char *str;

	if (!(str = ft_strnew(4)))
		return ;
	str[0] = (unicode >> 18) + 0xf0;
	str[1] = (unicode >> 12 & 0x3f) + 0x80;
	str[2] = (unicode >> 6 & 0x3f) + 0x80;
	str[3] = (unicode & 0x3f) + 0x80;
	fill_buff_c(data, str[0]);
	fill_buff_c(data, str[1]);
	fill_buff_c(data, str[2]);
	fill_buff_c(data, str[3]);
	ft_strdel(&str);
}

void	write_triple(wchar_t unicode, t_data *data)
{
	char *str;

	if (!(str = ft_strnew(3)))
		return ;
	str[0] = (unicode >> 12) + 0xe0;
	str[1] = (unicode >> 6 & 0x3f) + 0x80;
	str[2] = (unicode & 0x3f) + 0x80;
	fill_buff_c(data, str[0]);
	fill_buff_c(data, str[1]);
	fill_buff_c(data, str[2]);
	ft_strdel(&str);
}

void	write_double(wchar_t unicode, t_data *data)
{
	char *str;

	if (!(str = ft_strnew(2)))
		return ;
	str[0] = (unicode >> 6) + 0xc0;
	str[1] = (unicode & 0x3f) + 0x80;
	fill_buff_c(data, str[0]);
	fill_buff_c(data, str[1]);
	ft_strdel(&str);
}

int	pick_f_w(t_data *data, va_list param)
{
	wchar_t unicode;
	
	unicode = va_arg(param, wchar_t);
	if (unicode < 129)
	{
		fill_buff_c(data, unicode);
	}
	else if (unicode < 2049)
	{
		write_double(unicode, data);
	}
	else if (unicode < 55295)
	{
		write_triple(unicode, data);
	}
	else if (unicode < 2097152)
	{
		write_quadruple(unicode, data);
	}
	else
		data->ret_val = -1;
	return (0);
}
