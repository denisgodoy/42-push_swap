/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:34:13 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/29 21:01:01 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../42-libft/libft.h"
# include <stdio.h>

enum e_digits
{
	str,
	cmd
};

typedef struct s_sort
{
	int	prev;
	int	num;
	int	next;
}	t_sort;

typedef struct s_ps
{
	int		*args;
	char	**temp;
	int		len;
	t_sort	sort;
}	t_ps;

int	ft_check_args(t_ps *push_swap, int argc, char **argv);
int	ft_check_digits(t_ps *push_swap, char *arg, int direct);
int	ft_free_arr(char **args);
int	ft_is_duplicate(t_ps *push_swap);
int	ft_sort_arr(t_ps *push_swap);

#endif
