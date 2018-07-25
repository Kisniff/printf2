/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehideu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:59:43 by jlehideu          #+#    #+#             */
/*   Updated: 2018/07/23 16:34:48 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <limits.h>

static int	printuntil(const char *str, const char *ptr, t_data *data)
{
	int i;

	i = -1;
	while (str[++i] && str + i != ptr && str[i] != '\0' && str[i] != '%')
	{
		print_char(str[i], data);
	}
	return (i);
}

void		init_struct(t_data *data)
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

int			init_printf(t_data *data, const char *str)
{
	init_struct(data);
	data->ret_val = 0;
	data->idx = -1;
	if (!ft_strcmp((char *)str, "%") && ft_strlen(str) == 1)
		return (0);
	return (1);
}

int			ft_printf(const char *str, ...)
{
	va_list	pointerlst;
	char	*ptr;
	int		i;
	t_data	data;

	va_start(pointerlst, str);
	if (init_printf(&data, str) == 0)
		return (0);
	while ((ptr = ft_strchr(str, '%')) != NULL)
	{
		init_struct(&data);
		printuntil(str, ptr, &data);
		ptr += 1;
		while (ptr && (i = path(ptr, pointerlst, &data)) > 0)
			ptr += i;
		str = ptr + 1;
		if (data.ret_val > 0)
			write(1, &data.buff, ++data.idx);
		data.idx = -1;
	}
	printuntil(str, ptr, &data);
	if (data.ret_val > -1)
		write(1, &data.buff, ++data.idx);
	va_end(pointerlst);
	return (data.ret_val);
}

int main ()
{
	wchar_t hihi;

	setlocale(LC_ALL, "");
	hihi = L'é';
	printf("Vret -> %d\n", printf("%C\n", hihi));
	printf("Nret -> %d\n", ft_printf("%C\n", hihi));

}
