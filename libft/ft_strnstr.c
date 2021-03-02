/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:00:55 by da-lee            #+#    #+#             */
/*   Updated: 2020/11/16 21:35:46 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (!little[0])
	{
		return ((char *)big);
	}
	while (big[i] && (i < len))
	{
		j = 0;
		while (little[j])
		{
			if ((i + j) >= len || big[i + j] != little[j])
				break ;
			j++;
		}
		if (!little[j])
			return ((char *)big + i);
		i++;
	}
	return (0);
}
