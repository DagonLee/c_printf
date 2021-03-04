/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:30:37 by da-lee            #+#    #+#             */
/*   Updated: 2021/03/04 11:09:11 by da-lee           ###   ########.fr       */
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
