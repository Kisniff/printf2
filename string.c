/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:13:59 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/23 17:05:04 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	fill_buff_s(t_data *data, int i, char *str)
{
	int	j;

	j = -1;
	if (i == -1)
	{
		write(1, &data->buff, data->idx);
	}
	else if (i + data->idx <= BUFF_SIZE)
	{
		while (--i >= 0 && str[++j])
		{
			data->buff[++data->idx] = str[j];
			++data->ret_val;
		}
	}
	else if (i + data->idx > BUFF_SIZE)
	{
		write(1, &data->buff, BUFF_SIZE);
		data->idx = 0;
		ft_memset(data->buff, '\0', BUFF_SIZE);
		fill_buff_s(data, i, str);
	}
	return (0);
}

int	fill_buff_c(t_data *data, char c)
{
	if (data->idx + 1 <= BUFF_SIZE)
	{
		data->buff[++data->idx] = c;
		++data->ret_val;
	}
	else if (1 + data->idx > BUFF_SIZE)
	{
		write(1, &data->buff, BUFF_SIZE);
		data->idx = 0;
		ft_memset(data->buff, '\0', BUFF_SIZE);
		fill_buff_c(data, c);
	}
	return (0);
}

int	pick_f_s(const char *ptr, t_data *data, va_list param)
{
	char *str;
	if (*ptr == 'S' || (*ptr == 's' && data->flags[L] == 1))
	{
		str = va_arg(param, char*);
	}

	return (0);
}

int	string_param(t_data *data, va_list param)
{
	char *str;

	str = va_arg(param, char*);
	print_str(str, data);
	return (0);
}

int	print_str(char *str, t_data *data)
{//un putstr qui incrémente notre valeur de retour
	int	i;

	i = ft_strlen(str);
	fill_buff_s(data, i, str);
	return (data->ret_val);
}

void	print_char(char c, t_data *data)
{
	fill_buff_c(data, c);
}
