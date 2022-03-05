/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 22:38:13 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/06 17:53:25 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str_dst;
	char	*str_src;

	str_dst = (char *)dst;
	str_src = (char *)src;
	if (&str_src[0] >= &str_dst[0])
		return (ft_memcpy(str_dst, str_src, len));
	while (len--)
		str_dst[len] = str_src[len];
	return (dst);
}
