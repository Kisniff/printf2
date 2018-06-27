/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuntil.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:42:33 by sklepper          #+#    #+#             */
/*   Updated: 2018/05/31 17:11:20 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const char	*ft_printuntil(char *str, const char *ptr)
{
	size_t i;

	i = 0;
	while (str + i != ptr && str[i] != '\0')
		i++;
	write(1, str, i);
	return (str + i);
}