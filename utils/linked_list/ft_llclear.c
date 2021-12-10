/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:00:18 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/10 20:42:43 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_llclear(t_sort **lst, void (*del)(void *))
{
	t_sort	*node;
	t_sort	*nxt;

	while (*lst != NULL)
	{
		nxt = *lst;
		node = nxt->next;
		del((*lst));
		*lst = node;
	}
	*lst = NULL;
}
