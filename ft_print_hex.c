/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:26:33 by da-lee            #+#    #+#             */
/*   Updated: 2021/03/10 11:07:39 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_str_toupper(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		str[i] = ft_toupper(str[i]);
	return (str);
}

static int		ft_in_put_part_hexa(char *hexa, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.prec >= 0)
		char_count += ft_print_width(flags.prec - 1, ft_strlen(hexa) - 1, 1);
	char_count += ft_putstr(hexa, ft_strlen(hexa));
	return (char_count);
}

static int		ft_put_part_hexa(char *hexa, t_flags flags)
{
	int cnt;

	cnt = 0;
	if (flags.minus == 1)
		cnt += ft_in_put_part_hexa(hexa, flags);
	if (flags.prec >= 0 && flags.prec < ft_strlen(hexa))
		flags.prec = ft_strlen(hexa);
	if (flags.prec >= 0)
	{
		flags.width -= flags.prec;
		cnt += ft_print_width(flags.width, 0, 0);
	}
	else
		cnt += ft_print_width(flags.width, ft_strlen(hexa), flags.zero);
	if (flags.minus == 0)
		cnt += ft_in_put_part_hexa(hexa, flags);
	return (cnt);
}

int				ft_print_hex(unsigned int ui, int lower, t_flags flags)
{
	char	*hexa;
	int		cnt;

	cnt = 0;
	ui = (unsigned int)(4294967295 + 1
				+ ui);
	if (flags.prec == 0 && ui == 0)
	{
		cnt += ft_print_width(flags.width, 0, 0);
		return (cnt);
	}
	hexa = ft_dec_to_hex(ui);
	if (lower == 0)
		hexa = ft_str_toupper(hexa);
	cnt += ft_put_part_hexa(hexa, flags);
	free(hexa);
	return (cnt);
}
