/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:15:58 by sklepper          #+#    #+#             */
/*   Updated: 2018/05/07 14:05:10 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoinch(char *s1, char c)
{
	int		i;
	char	*new;

	if (!s1 || !c)
		return (NULL);
	if (!(new = ft_strnew(ft_strlen(s1) + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = c;
	free(s1);
	return (new);
}
