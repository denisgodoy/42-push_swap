/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 21:06:45 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/06 17:53:17 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str_dst;
	char	*str_src;

	if (!dst && !src && n)
		return (0);
	str_src = (char *)src;
	str_dst = (char *)dst;
	while (n--)
		*(str_dst++) = *(str_src++);
	return (dst);
}
