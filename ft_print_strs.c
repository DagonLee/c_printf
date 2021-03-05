/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:10:28 by da-lee            #+#    #+#             */
/*   Updated: 2021/03/05 13:41:13 by da-lee           ###   ########.fr       */
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

int		ft_print_char(char c, t_flags flags)
{
	int cnt;

	cnt = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	cnt = ft_print_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (cnt + 1);
}

int		ft_print_str_part(char *str, t_flags flags)
{
	int cnt;

	cnt = 0;
	if (flags.prec >= 0)
	{
		cnt += ft_putstr(str, flags.prec);
	}
	else
	{
		cnt += ft_putstr(str, ft_strlen(str));
	}
	return (cnt);
}

int		ft_print_str(char *str, t_flags flags)
{
	int cnt;

	cnt = 0;
	if (!str)
		str = "(null)"; 
	if (flags.prec >= 0 && flags.prec > ft_strlen(str))
		flags.prec = ft_strlen(str);
	if (flags.minus == 1)
		cnt += ft_print_str_part(str, flags);
	if (flags.prec >= 0)
		cnt += ft_print_width(flags.width, flags.prec, 0);
	else
		cnt += ft_print_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		cnt += ft_print_str_part(str, flags);
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
