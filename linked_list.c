/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:00:18 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/10 18:22:06 by degabrie         ###   ########.fr       */
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
	new->next = NULL;
	return (new);
}

t_sort	*ft_lllast(t_sort *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
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

int	ft_llsize(t_sort *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

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
