/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:30:13 by da-lee            #+#    #+#             */
/*   Updated: 2021/03/11 16:21:43 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_int_part(char *str, t_flags flags)
{
	int cnt;

	cnt = 0;
	cnt += ft_print_width(flags.prec, ft_strlen(str), 1);
	cnt += ft_putstr(str, ft_strlen(str));
	return (cnt);
}

int			ft_print_int_order_min(t_flags flags, char *str, int zero_check)
{
	int cnt;

	cnt = 0;
	if (flags.minus == 1)
	{
		cnt += ft_putchar('-');
		cnt += ft_print_int_part(str, flags);
	}
	if (flags.zero == 1)
	{
		cnt += ft_putchar('-');
		zero_check = 1;
	}
	cnt += ft_print_width(flags.width, flags.prec + 1, flags.zero);
	if (flags.minus == 0)
	{
		if (zero_check == 0)
			cnt += ft_putchar('-');
		cnt += ft_print_int_part(str, flags);
	}
	return (cnt);
}

int			ft_print_int_order(char *str, int v_min, t_flags flags)
{
	int		cnt;
	int		zero_check;

	zero_check = 0;
	cnt = 0;
	if (flags.prec >= 0)
		flags.zero = 0;
	if (flags.prec < ft_strlen(str))
		flags.prec = ft_strlen(str);
	if (v_min == 1)
		cnt += ft_print_int_order_min(flags, str, zero_check);
	else
	{
		if (flags.minus == 1)
			cnt += ft_print_int_part(str, flags);
		cnt += ft_print_width(flags.width, flags.prec, flags.zero);
		if (flags.minus == 0)
			cnt += ft_print_int_part(str, flags);
	}
	return (cnt);
}

int			ft_print_int(int value, t_flags flags)
{
	char		*str;
	int			save;
	long long	v;
	int			cnt;
	int			v_min;

	v_min = 0;
	v = value;
	save = value;
	cnt = 0;
	if (flags.prec == 0 && value == 0)
	{
		cnt += ft_print_width(flags.width, 0, 0);
		return (cnt);
	}
	if (value < 0)
	{
		v_min = 1;
		v *= -1;
	}
	str = ft_lltoa(v);
	cnt = ft_print_int_order(str, v_min, flags);
	free(str);
	return (cnt);
}
