/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:16:09 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/06 18:02:32 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*nxt;

	while (*lst != 0)
	{
		nxt = *lst;
		node = nxt->next;
		ft_lstdelone(*lst, (*del));
		*lst = node;
	}
	*lst = 0;
}
