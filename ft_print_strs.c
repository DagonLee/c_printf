/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:10:28 by da-lee            #+#    #+#             */
/*   Updated: 2021/03/11 21:42:12 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_width(int width, int minus, int zero)
{
	int cnt;

	cnt = 0;
	while (width - minus > 0)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		cnt++;
	}
	return (cnt);
}

int		ft_print_char(char value, t_flags flags)
{
	int		cnt;

	cnt = 0;
	if (flags.minus == 1)
		cnt += ft_putchar(value);
	cnt += ft_print_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		cnt += ft_putchar(value);
	return (cnt);
}

int		ft_print_str_part(t_flags flags, char *value)
{
	int cnt;

	cnt = 0;
	cnt += ft_print_width(flags.prec, ft_strlen(value), 0);
	cnt += ft_putstr(value, flags.prec);
	return (cnt);
}

int		ft_print_str(char *value, t_flags flags)
{
	int cnt;

	cnt = 0;
	if (!value)
		value = "(null)";
	if (flags.prec == 0)
		value = "";
	if (flags.prec <= -1)
		flags.prec = ft_strlen(value);
	if (flags.prec > ft_strlen(value))
		flags.prec = ft_strlen(value);
	if (flags.minus == 1)
		cnt += ft_print_str_part(flags, value);
	cnt += ft_print_width(flags.width, flags.prec, flags.zero);
	if (flags.minus == 0)
		cnt += ft_print_str_part(flags, value);
	return (cnt);
}

int		ft_print_percent(t_flags flags)
{
	int cnt;

	cnt = 0;
	if (flags.minus == 1)
		cnt += ft_putstr("%", 1);
	cnt += ft_print_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		cnt += ft_putstr("%", 1);
	return (cnt);
}
