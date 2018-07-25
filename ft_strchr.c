/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehideu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:57:11 by jlehideu          #+#    #+#             */
/*   Updated: 2018/07/23 16:03:35 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;
	int			i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
		ptr = s + i;
	else
		ptr = NULL;
	return (char *)(ptr);
}
