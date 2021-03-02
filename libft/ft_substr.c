/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:08:45 by da-lee            #+#    #+#             */
/*   Updated: 2020/11/16 21:43:06 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	size;
	char			*str;
	size_t			n_len;

	if (!s)
		return (0);
	size = ft_strlen(s);
	n_len = ft_strlen(s + start);
	if (n_len < len)
	{
		len = n_len;
	}
	if (size < start)
	{
		return (ft_strdup(""));
	}
	else if (s)
	{
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
		ft_strlcpy(str, s + start, len + 1);
		return (str);
	}
	return (0);
}
