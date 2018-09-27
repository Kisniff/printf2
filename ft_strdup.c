/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:59:18 by sklepper          #+#    #+#             */
/*   Updated: 2018/07/23 15:59:19 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(char *src)
{
	size_t		nb_char;
	size_t		i;
	char		*dest;

	nb_char = (size_t)ft_strlen(src);
	if (!(dest = ft_strnew(nb_char)))
		return (0);
	i = 0;
	while (i < nb_char)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
