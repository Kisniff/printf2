/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:58:27 by sklepper          #+#    #+#             */
/*   Updated: 2018/07/23 15:58:30 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	char *new;

	new = malloc(sizeof(char) * size + 1);
	if (new == NULL)
		return (NULL);
	ft_memset(new, '\0', size + 1);
	return (new);
}
