/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:12:10 by da-lee            #+#    #+#             */
/*   Updated: 2020/11/16 20:46:31 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp;
	const unsigned char	*str;

	tmp = dst;
	str = src;
	if (dst == src)
		return (0);
	while (len--)
		*tmp++ = *str++;
	return (dst);
}
