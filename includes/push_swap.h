/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:34:13 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/22 20:04:08 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../42-libft/libft.h"
# include <stdio.h>

typedef struct s_ps
{
	int		*args;
	char	**temp;
	int		arr_len;
}	t_ps;

int	ft_free_arr(char **args);
int	ft_is_duplicate(t_ps *push_swap);
int	ft_check_digits(t_ps *push_swap, char *arg, int direct);

#endif