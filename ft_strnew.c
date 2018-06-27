/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 14:16:13 by sklepper          #+#    #+#             */
/*   Updated: 2018/06/19 16:56:29 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new;

	new = malloc(sizeof(char) * size + 1);
	if (new == NULL)
		return (NULL);
	ft_memset(new, '\0', size + 1);
	return (new);
}
