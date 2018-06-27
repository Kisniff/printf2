/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:16:03 by sklepper          #+#    #+#             */
/*   Updated: 2018/05/07 14:05:10 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *ptr;

	ptr = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			ptr = s;
		s++;
	}
	if (*s == c)
		ptr = s;
	return (char *)(ptr);
}
