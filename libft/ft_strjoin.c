/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:58:26 by da-lee            #+#    #+#             */
/*   Updated: 2020/11/16 21:48:35 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size1;
	int		size2;

	if (!s1 || !s2)
		return (0);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(str = (char *)malloc((size1 + size2 + 1) * sizeof(char))))
		return (0);
	if (!size2)
	{
		ft_strlcpy(str, s1, size1 + 1);
	}
	else if (!size1)
	{
		ft_strlcpy(str, s2, size2 + 1);
	}
	else
	{
		ft_strlcpy(str, s1, size1 + 1);
		ft_strlcat(str + size1, s2, size2 + 1);
	}
	return (str);
}
