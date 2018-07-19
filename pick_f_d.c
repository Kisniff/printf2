/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_f_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:13:50 by sklepper          #+#    #+#             */
/*   Updated: 2018/07/19 13:38:30 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	sign_d(t_data *data, int sign)
{
	char s[2];

	s[0] = '+';
	s[1] = '-';
	if (data->flags[SPACE] == 1 && data->flags[MINUS] == 0)
	{
		s[0] = ' ';
		s[1] = '-';
	}
	if (data->width > data->precision + (int)data->len
		&& data->flags[MINUS] == 0 && data->idx >= 0)
		data->buff[data->idx] = s[sign];
	else
	{
		fill_buff_c(data, s[sign]);
		data->sign = 1;
	}
}

static void		flags_d(t_data *data, int neg, char *str)
{
	if (data->flags[MINUS] == 0 && data->flags[ZERO] == 0)
		f_width(data);
	else if (data->flags[ZERO] == 1 && data->flags[MINUS] == 0)
	{
		if ((data->flags[PLUS] == 1 || neg == 1 || data->flags[SPACE] == 1))
			sign_d(data, neg);
		f_zero(data);
	}
	if ((data->flags[PLUS] == 1 || neg == 1 || data->flags[SPACE] == 1) && data->flags[ZERO] == 0)
		sign_d(data, neg);
	f_precision(data);
	write_str(data, str);
	if (data->flags[MINUS] == 1)
		f_width(data);
}

static int		ft_int(t_data *data, long long n)
{
	char *str;
	int neg;

	if (n < 0)
		str = ft_itoa_long(-n);
	else
		str = ft_itoa_long(n);
	neg = ft_isneg(n);
	data->len = ft_strlen(str);
	data->precision = (data->precision > (int)data->len) ? (int)(data->precision - data->len) : 0;
	flags_d(data, neg, str);
	free(str);
	return (0);
}

int			pick_f_d(va_list param, t_data *data)
{
	long long n;

	if (data->length[L] == 1)
		n = va_arg(param, long);
	else if (data->length[L] == 2)
		n = va_arg(param, long long);
	else if (data->length[H] == 1)
		n = (short)va_arg(param, int);
	else if (data->length[H] == 2)
		n = (signed char)va_arg(param, int);
	else
		n = va_arg(param, int);
	ft_int(data, n);
	return (0);
}
