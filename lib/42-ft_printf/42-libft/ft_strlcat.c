/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:53:06 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/06 17:54:50 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size;
	size_t	i;

	size = ft_strlen(dst);
	i = 0;
	if (dstsize > size)
	{
		while (i < dstsize - size - 1 && src[i] != '\0')
		{
			dst[size + i] = src[i];
			i++;
		}
		dst[size + i] = '\0';
		return (size + ft_strlen(src));
	}
	return (dstsize + ft_strlen(src));
}
