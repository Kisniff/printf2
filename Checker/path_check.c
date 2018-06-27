/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:36:26 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/20 15:55:16 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		width_check(const char *ptr, t_data *data)
{
<<<<<<< HEAD:path_check.c
/*	if (*ptr == '.')
=======
	if (*ptr == '.')
	{
		if (data->precision != 0)
			return (-1);
>>>>>>> 97fb9986336934f7be98d36bd65f8f264c385b92:Checker/path_check.c
		return (precision(ptr + 1, data) + 1);
	}
	else if (*ptr > '0' && *ptr <= '9')
<<<<<<< HEAD:path_check.c
		return (width_min(ptr, data));*/
=======
	{
		if (data->width != 0)
			return (-1);
		return (width_min(ptr, data));
	}
>>>>>>> 97fb9986336934f7be98d36bd65f8f264c385b92:Checker/path_check.c
	return (0);
}

int		flags_check(const char *ptr, t_data *data)
{
	/*if (*ptr == '#')
		return (flag_sharp(data));
	else if (*ptr == '0')
		return (flag_zero(data, ptr));
	else if (*ptr == '-')
		return (flag_minus(data));
	else if (*ptr == '+')
		return (flag_plus(data));
	else if (*ptr == ' ')
		return (flag_space(data));*/
	return (0);
}

int		length_check(const char *ptr, t_data *data)
{
/*	if (*ptr == 'h')
		return (length_h(ptr, data));
	else if (*ptr == 'l')
		return (length_l(ptr, data));
	else if (*ptr == 'j')
		return (length_j(data));
	else if (*ptr == 'z')
		return (length_z(data));*/
	return (0);
}

<<<<<<< HEAD:path_check.c
int		check_s(t_data *data)
{
	/*if (data->length[H] > 0 || data->length[L] > 1 || data->length[J] > 0 ||
			data->length[Z] > 0)
		return (-1);
	if (data->flags[SHARP] > 0 || data->flags[ZERO] > 0 ||
			data->flags[SPACE] > 0 || data->flags[PLUS] > 0)*/
		return (-1);
}

int		conversion_check(const char *ptr, t_data *data)
{
	/*if (*ptr == 's' || *ptr == 'S')
=======

int		conversion_check(const char *ptr, t_data *data)
{
	if (*ptr == 's' || *ptr == 'c')
>>>>>>> 97fb9986336934f7be98d36bd65f8f264c385b92:Checker/path_check.c
		return (check_s(data));
	else if (*ptr == 'S' || *ptr == 'C' || *ptr == 'p')
		return (check_s_c_p(data));
	else if (*ptr == 'd' || *ptr == 'i' || *ptr == 'D')
		return (check_di(data));
	else if (*ptr == 'o' || *ptr == 'O' || *ptr == 'x' || *ptr == 'X')
		return (check_ox(data));
	else if (*ptr == 'u' || *ptr == 'U')
<<<<<<< HEAD:path_check.c
		pick_f_u(data);
	else if (*ptr == 'x' || *ptr == 'X')
		pick_f_x(data, ptr);
	else if (*ptr == 'c' || *ptr == 'C')
		pick_f_c(data);*/
	return (0);
=======
		return (check_u(data));
	return (-1);
>>>>>>> 97fb9986336934f7be98d36bd65f8f264c385b92:Checker/path_check.c
}

int		path_check(char *ptr, t_data *data)
{
/*	int i;

	i = 0;
	if ((i = flags_check(ptr, data)) > 0)
		return (i);
	else if ((i = length_check(ptr, data)) > 0)
		return (i);
	else if ((i = width_check(ptr, data)) > 0)
		return (i);
	else if (*ptr == '%')
		return (0);
	else
		conversion_check(ptr, data);*/
	return (0);
}
<<<<<<< HEAD:path_check.c
=======

int		check(const char *str)
{
	t_data	data;
	const char	*ptr;
	int		i;

	ptr = str;
	while ((ptr = ft_strchr(str, '%')) != NULL)
	{
		init_struct(&data);
		ptr += 1;
		while (flags_check(ptr, &data) > 0)
			ptr += 1;
		while ((i = width_check(ptr, &data)) > 0)
			ptr += i;
		if (i == -1 || conversion_check(ptr, &data) == -1)
			return (-1);
		str = ptr + 1;
	}
	return (0);
}
>>>>>>> 97fb9986336934f7be98d36bd65f8f264c385b92:Checker/path_check.c
