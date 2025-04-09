/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noavetis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:35:55 by noavetis          #+#    #+#             */
/*   Updated: 2025/01/29 17:47:22 by noavetis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ob;

	ob = malloc(sizeof(t_list));
	if (!ob)
		return (NULL);
	ob->content = content;
	ob->next = NULL;
	return (ob);
}
