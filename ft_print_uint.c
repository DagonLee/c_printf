/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:29:12 by da-lee            #+#    #+#             */
/*   Updated: 2021/03/12 11:39:12 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_uitoa(unsigned int value)
{
	int				len;
	unsigned int	v;
	char			*radix;
	char			*result;

	len = 1;
	v = value;
	while (v /= 10)
		len++;
	if ((result = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	radix = ft_strdup("0123456789");
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = radix[value % 10];
		value /= 10;
	}
	free(radix);
	return (result);
}

int				ft_print_uint_part(t_flags flags, char *str_uint)
{
	int cnt;

	cnt = 0;
	cnt += ft_print_width(flags.prec, ft_strlen(str_uint), 1);
	cnt += ft_putstr(str_uint, ft_strlen(str_uint));
	return (cnt);
}

int				ft_print_uint_order(t_flags flags, char *str_uint)
{
	int cnt;

	cnt = 0;
	if (flags.prec >= 0)
		flags.zero = 0;
	if (flags.prec < ft_strlen(str_uint))
		flags.prec = ft_strlen(str_uint);
	if (flags.minus == 1)
		cnt += ft_print_uint_part(flags, str_uint);
	cnt += ft_print_width(flags.width, flags.prec, flags.zero);
	if (flags.minus == 0)
		cnt += ft_print_uint_part(flags, str_uint);
	return (cnt);
}

int				ft_print_uint(unsigned int value, t_flags flags)
{
	char			*str_uint;
	int				cnt;

	cnt = 0;
	if (flags.prec == 0 && value == 0)
	{
		cnt += ft_print_width(flags.width, 0, 0);
		return (cnt);
	}
	str_uint = ft_uitoa(value);
	cnt += ft_print_uint_order(flags, str_uint);
	free(str_uint);
	return (cnt);
}
