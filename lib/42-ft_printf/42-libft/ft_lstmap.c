/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 19:30:32 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/06 17:52:39 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstmap(t_list *lst, void	*(*f)(void *), void	(*del)(void *))
{
	t_list	*node;

	if (!lst)
		return (0);
	node = ft_lstnew((*f)(lst->content));
	if (!node)
	{
		ft_lstclear(&node, (*del));
		return (0);
	}
	node->next = ft_lstmap(lst->next, (*f), (*del));
	return (node);
}
