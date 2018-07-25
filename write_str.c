/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehideu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:48:06 by jlehideu          #+#    #+#             */
/*   Updated: 2018/07/23 15:49:40 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_str(t_data *data, char *str)
{
	int	i;

	i = -1;
	while (++i < data->len)
		fill_buff_c(data, str[i]);
	return (0);
}