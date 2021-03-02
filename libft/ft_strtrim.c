/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:21:26 by da-lee            #+#    #+#             */
/*   Updated: 2020/11/16 21:49:35 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_char_in_str(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		start;
	int		end;

	start = 0;
	if (!s1 || !set)
		return (0);
	end = ft_strlen(s1);
	i = 0;
	while (s1[start] && ft_char_in_str(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_in_str(s1[end - 1], set))
		end--;
	if (!(str = (char*)malloc(sizeof(char) * (end - start + 1))))
		return (0);
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
