/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:24:06 by sklepper          #+#    #+#             */
/*   Updated: 2018/05/07 14:00:54 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;

	if (alst == NULL && del == NULL)
		return ;
	while (*alst != NULL)
	{
		next = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = next;
	}
	*alst = NULL;
}
