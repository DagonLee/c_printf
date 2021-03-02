/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:44:57 by da-lee            #+#    #+#             */
/*   Updated: 2020/11/10 18:48:14 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	*str;

	i = 0;
	tmp = (unsigned char *)dst;
	str = (unsigned char *)src;
	while (i < len)
	{
		tmp[i] = str[i];
		if (tmp[i] == (unsigned char)c)
			return ((void *)(dst + i + 1));
		i++;
	}
	return (0);
}
