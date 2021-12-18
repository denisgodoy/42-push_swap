/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:34:13 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/17 22:01:09 by degabrie         ###   ########.fr       */
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
	int				num;
	struct s_sort	*next;
}	t_sort;

typedef struct s_ps
{
	int		*args;
	char	**temp;
	int		len;
	int		last;
	int		min;
	int		max;
	int		mid;
	t_sort	*stack_a;
	t_sort	*stack_b;
}	t_ps;

void	ft_algorithm(t_ps *push_swap);
int		ft_check_args(t_ps *push_swap, int argc, char **argv);
int		ft_check_digits(t_ps *push_swap, char *arg, int direct);
int		ft_free_arr(char **args);
void	ft_init_stacks(t_ps *push_swap);
int		ft_is_duplicate(t_ps *push_swap);
int		ft_is_sorted(t_ps *push_swap);
void	ft_sort_arr(t_ps *push_swap);

void	ft_push(t_sort **src, t_sort **dst, char *op);
void	ft_reverse_rotate(t_sort **stack, char *op);
void	ft_rotate(t_sort **stack, char *op);
void	ft_swap(t_sort **stack, char *op);
void	ft_reverse_rotate_both(t_ps *push_swap);
void	ft_rotate_both(t_ps *push_swap);
void	ft_swap_both(t_ps *push_swap);

void	ft_lladd_back(t_sort **lst, t_sort *new);
void	ft_lladd_front(t_sort **lst, t_sort *new);
void	ft_llclear(t_sort **lst, void (*del)(void *));
t_sort	*ft_lllast(t_sort *lst);
t_sort	*ft_llnew(int content);
int		ft_llsize(t_sort *lst);

#endif
