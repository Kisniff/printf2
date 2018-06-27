/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:21:15 by sklepper          #+#    #+#             */
/*   Updated: 2018/05/07 14:03:53 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char *str1;
	unsigned const char *str2;
	size_t				i;

	i = (size_t)-1;
	str1 = (const unsigned char*)s1;
	str2 = (const unsigned char*)s2;
	while (++i < n && *(str1 + i) == *(str2 + i))
		;
	if (i == n)
		return (0);
	return (*(str1 + i) - *(str2 + i));
}
