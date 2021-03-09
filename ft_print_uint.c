/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:29:12 by da-lee            #+#    #+#             */
/*   Updated: 2021/03/09 15:26:14 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_u_itoa(uintmax_t value)
{
	int			len;
	uintmax_t	v;
	char		*radix;
	char		*result;

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

static int	ft_in_put_part_uint(char *unsi_int, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.prec >= 0)
		char_count += ft_print_width(flags.prec - 1, ft_strlen(unsi_int) - 1, 1);
	char_count += ft_putstr(unsi_int, ft_strlen(unsi_int));
	return (char_count);
}

static int	ft_put_part_uint(char *unsi_int, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_in_put_part_uint(unsi_int, flags);
	if (flags.prec >= 0 && flags.prec < ft_strlen(unsi_int))
		flags.prec = ft_strlen(unsi_int);
	if (flags.prec >= 0)
	{
		flags.width -= flags.prec;
		char_count += ft_print_width(flags.width, 0, 0);
	}
	else
		char_count += ft_print_width(flags.width,
		ft_strlen(unsi_int), flags.zero);
	if (flags.minus == 0)
		char_count += ft_in_put_part_uint(unsi_int, flags);
	return (char_count);
}

int		ft_print_uint(unsigned int n, t_flags flags)
{
	uintmax_t num;
	char *uint_str;
	int cnt;

	num = n;
	cnt = 0;
	if (flags.prec == 0 && num == 0)
	{
		cnt += ft_print_width(flags.width, 0, 0);
		return (cnt);
	}
	uint_str = ft_u_itoa(num);
	cnt += ft_put_part_uint(uint_str, flags);
	free(uint_str);
	return (cnt);
}
