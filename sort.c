/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:01:20 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/29 20:10:07 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	*ft_intdup(int *arr, int len);
static int	ft_get_median(int flag, int *arr, t_ps *push_swap);

int	ft_sort_arr(t_ps *push_swap)
{
	int	temp;
	int	*arr;
	int	flag;
	int	i;
	int	j;

	arr = ft_intdup(push_swap->args, push_swap->len);
	flag = 0;
	i = -1;
	while (++i < push_swap->len)
	{
		j = i;
		while (++j < push_swap->len)
		{
			if (arr[i] > arr[j])
			{
				flag = 1;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return (ft_get_median(flag, arr, push_swap));
}

static int	*ft_intdup(int *arr, int len)
{
	int	*new_arr;
	int	i;

	new_arr = (int *)malloc(len * sizeof(int));
	i = -1;
	while (++i < len)
		new_arr[i] = arr[i];
	return (new_arr);
}

static int	ft_get_median(int flag, int *arr, t_ps *push_swap)
{
	int	median;

	if (!flag)
	{
		free(push_swap->args);
		exit(EXIT_FAILURE);
	}
	else if (push_swap->len % 2 != 0)
		median = arr[push_swap->len / 2];
	else
		median = (arr[push_swap->len / 2] + arr[push_swap->len / 2 - 1]) / 2;
	free(arr);
	return (median);
}