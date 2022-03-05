/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:28:40 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/06 17:51:54 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	ft_count_decimal(long int n);

char	*ft_itoa(int n)
{
	long int	nbr;
	int			i;
	char		*ptr;

	nbr = n;
	ptr = (char *)ft_calloc(ft_count_decimal(nbr) + 1, sizeof(char));
	if (!ptr)
		return (0);
	if (n == 0)
		ptr[0] = '0';
	i = ft_count_decimal(nbr) - 1;
	if (nbr < 0)
	{
		nbr *= -1;
		ptr[0] = '-';
	}
	while (nbr > 0)
	{
		ptr[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	return (ptr);
}

static int	ft_count_decimal(long int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		i = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
