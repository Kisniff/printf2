/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:13:59 by sklepper          #+#    #+#             */
/*   Updated: 2018/07/09 18:14:32 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	fill_buff_c(t_data *data, char c)
{
	if (data->ret_val == -1)
		return (0);
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

int	print_str(char *str, t_data *data, char *ptr)
{//un putstr qui incrémente notre valeur de retour
	int	i;

	i = -1;
	if (*ptr == 's' || *ptr == 'S')
		while (str[++i] && i < data->len)
			fill_buff_c(data, str[i]);
	else
		while (str[++i])
			fill_buff_c(data, str[i]);
	return (data->ret_val);
}

void	print_char(char c, t_data *data)
{
	fill_buff_c(data, c);
}
