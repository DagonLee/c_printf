/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:40:10 by da-lee            #+#    #+#             */
/*   Updated: 2020/11/08 19:22:47 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr_dst;
	unsigned char		*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (dst == src || n == 0)
		return (dst);
	if (ptr_dst < ptr_src)
	{
		while (n--)
			*(ptr_dst++) = *(ptr_src++);
	}
	else
	{
		ptr_dst += n;
		ptr_src += n;
		while (n--)
			*(--ptr_dst) = *(--ptr_src);
	}
	return (dst);
}
