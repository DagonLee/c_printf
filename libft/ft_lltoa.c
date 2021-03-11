/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:05:19 by da-lee            #+#    #+#             */
/*   Updated: 2021/03/11 10:10:04 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_len(long long n)
{
	int				cnt;
	long long		nbr;

	cnt = 0;
	nbr = n;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		cnt++;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		cnt++;
	}
	return (cnt);
}

int			ft_abs(long long nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

char		*ft_lltoa(long long n)
{
	char			*str;
	int				len;
	int				limit;

	len = ft_count_len(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len] = 0;
	limit = 0;
	if (n < 0)
	{
		limit = 1;
		str[0] = '-';
	}
	len--;
	while (len >= limit)
	{
		str[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		len--;
	}
	return (str);
}
