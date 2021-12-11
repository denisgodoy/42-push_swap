/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lladd_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:41:38 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/10 22:25:02 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_lladd_back(t_sort **lst, t_sort *new)
{
	t_sort	*node;

	if (*lst != NULL)
	{
		node = ft_lllast(*lst);
		node->next = new;
		return ;
	}
	*lst = new;
}
