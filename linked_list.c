/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:00:18 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/10 11:01:08 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

t_sort	*ft_llnew(int content)
{
	t_sort	*new;

	new = (t_sort *)malloc(sizeof(t_sort));
	if (!new)
		return (0);
	new->num = content;
	new->next = 0;
	return (new);
}

t_sort	*ft_lllast(t_sort *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

void	ft_lladd_back(t_sort **lst, t_sort *new)
{
	t_sort	*node;

	if (*lst != 0)
	{
		node = ft_lllast(*lst);
		node->next = new;
		return ;
	}
	*lst = new;
}

void	ft_lladd_front(t_sort **lst, t_sort *new)
{
	new->next = *lst;
	*lst = new;
}
