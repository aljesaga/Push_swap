/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:04:05 by alsanche          #+#    #+#             */
/*   Updated: 2021/08/31 13:34:01 by alsanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;

	if (!lst)
		return (NULL);
	ft_lstnew(newlst);
	if (!newlst)
		return (NULL);
	ft_lstiter(newlst, lst);
	while (lst->content)
	{
		newlst = lst->content;
		newlst = newlst->next;
		lst = lst->next;
	}
	while (lst)
	{
		ft_lstclear(lst, del);
	}
	return (newlst);
}
