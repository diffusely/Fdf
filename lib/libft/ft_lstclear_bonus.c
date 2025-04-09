/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:05:42 by noavetis          #+#    #+#             */
/*   Updated: 2025/01/29 17:49:22 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*head;
	t_list	*temp;

	if (!lst)
		return ;
	temp = NULL;
	head = *lst;
	while (head)
	{
		temp = head;
		head = head->next;
		ft_lstdelone(temp, del);
	}
	*lst = NULL;
}
