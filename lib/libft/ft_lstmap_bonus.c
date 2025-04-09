/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 00:04:07 by noavetis          #+#    #+#             */
/*   Updated: 2025/01/29 17:49:51 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*temp;

	res = NULL;
	while (lst)
	{
		temp = malloc(sizeof(t_list));
		if (!temp)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		temp->content = f(lst->content);
		temp->next = NULL;
		ft_lstadd_back(&res, temp);
		lst = lst->next;
	}
	return (res);
}
