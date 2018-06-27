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
	write(1, &str[0], 1);
	write(1, &str[1], 1);
	write(1, &str[2], 1);
	write(1, &str[3], 1);
	ft_strdel(&str);
	data->ret_val = -1;
}

void	write_triple(wchar_t unicode, t_data *data)
{
	char *str;

	if (!(str = ft_strnew(3)))
		return ;
	str[0] = (unicode >> 12) + 0xe0;
	str[1] = (unicode >> 6 & 0x3f) + 0x80;
	str[2] = (unicode & 0x3f) + 0x80;
	write(1, &str[0], 1);
	write(1, &str[1], 1);
	write(1, &str[2], 1);
	ft_strdel(&str);
	data->ret_val += 4;
}

void	write_double(wchar_t unicode, t_data *data)
{
	char *str;

	if (!(str = ft_strnew(2)))
		return ;
	str[0] = (unicode >> 6) + 0xc0;
	str[1] = (unicode & 0x3f) + 0x80;
	write(1, &str[0], 1);
	write(1, &str[1], 1);
	ft_strdel(&str);
	data->ret_val += 3;
}

void	write_single(wchar_t unicode, t_data *data)
{
	char str;

	str = unicode;
	write(1, &str, 1);
	data->ret_val += 2;
}

int	pick_f_w(t_data *data, va_list param)
{
	wchar_t unicode;
	
	unicode = va_arg(param, wchar_t);
	if (unicode < 129)
		write_single(unicode, data);
	else if (unicode < 2049)
		write_double(unicode, data);
	else if (unicode < 55295)
		write_triple(unicode, data);
	else
		data->ret_val = -1;
	//	write_quadruple(unicode, data);
	return (0);
}
