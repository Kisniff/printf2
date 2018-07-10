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

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		write_w(data, str[i]);
	return (0);
}

int	pick_f_bigs(va_list param, t_data *data)
{
	wchar_t *str;
	
	str = va_arg(param, wchar_t *);
	if (!str)
		return (exception_bigs(data, "(null)"));
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
		f_width(data);
		write_bigs(data, str);
	}
	return (0);
}
