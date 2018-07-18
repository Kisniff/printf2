/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:53:50 by sklepper          #+#    #+#             */
/*   Updated: 2018/07/16 15:11:19 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <limits.h>

int	printuntil(const char *str, const char *ptr, t_data *data)
{
	int i;

	i = -1;
	while (str[++i] && str + i != ptr && str[i] != '\0' && str[i] != '%')
		print_char(str[i], data);
	return (i);
}

void	init_struct(t_data *data)
{
	int i;

	data->precision = 0;
	data->width = 0;
	data->len = 0;
	data->sign = 0;
	i = -1;
	while (++i <= 4)
		data->flags[i] = 0;
	i = -1;
	while (++i <= 4)
		data->length[i] = 0;
}

int	 ft_printf(const char *str, ...)
{
	va_list		pointerlst;
	char 		*ptr;
	int		i;
	t_data		data;

	va_start(pointerlst, str);
	init_struct(&data);
	data.ret_val = 0;
	data.idx = -1;
	while ((ptr = ft_strchr(str, '%')) != NULL)
	{
		init_struct(&data);
		printuntil(str, ptr, &data);
		ptr += 1;
		while (ptr && (i = path(ptr, pointerlst, &data)) > 0)
			ptr += i;
		str = ptr + 1;
	}
	printuntil(str, ptr, &data);
	if (data.ret_val > -1)
		write(1, &data.buff, ++data.idx);
	va_end(pointerlst);
	return (data.ret_val);
}


int main(void)
{//fix two commented codes@
	int	i;
	int ret;

	i = -987;
	ret = printf("Vous : %053d\n", i);
	printf("Vret : %d\n", ret);
	ret = ft_printf("Nous : %053d\n", i);
	printf("Nret : %d\n", ret);
	return (0);
}
