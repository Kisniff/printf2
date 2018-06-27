/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:15:21 by sklepper          #+#    #+#             */
/*   Updated: 2018/05/07 14:05:10 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strremb(char *str, char c)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (str[i] != c)
		i++;
	new = ft_strnew(ft_strlen(str) - ++i);
	j = 0;
	while (str[i] != '\0')
		new[j++] = str[i++];
	free(str);
	return (new);
}
