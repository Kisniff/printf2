/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:53:50 by sklepper          #+#    #+#             */
/*   Updated: 2018/07/10 17:32:49 by jlehideu         ###   ########.fr       */
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
	//if (check(str) == -1)
	//	return (-1);
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
/*
int main(void)
{//fix two commented codes@
//fail 0095
	int	i;
	int	ret;
	int	fd;
	wchar_t	s[4];

	setlocale(LC_ALL, "");
	i = 55295;
	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';
	printf("Vret -> %d\n", printf("vous -> %---10.5ls\n", s));
	printf("Nret -> %d\n", ft_printf("nous -> %---10.5ls\n", s));
	return (0);
}*/
