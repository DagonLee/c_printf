/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:26:33 by da-lee            #+#    #+#             */
/*   Updated: 2021/03/11 17:25:08 by da-lee           ###   ########.fr       */
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

int				ft_print_hex_part(t_flags flags, char *str_hex)
{
	int cnt;

	cnt = 0;
	cnt += ft_print_width(flags.prec, ft_strlen(str_hex), 1);
	cnt += ft_putstr(str_hex, ft_strlen(str_hex));
	return (cnt);
}

int				ft_print_hex_order(t_flags flags, char *str_hex)
{
	int cnt;

	cnt = 0;
	if (flags.prec >= 0)
		flags.zero = 0;
	if (flags.prec < ft_strlen(str_hex))
		flags.prec = ft_strlen(str_hex);
	if (flags.minus == 1)
		cnt += ft_print_hex_part(flags, str_hex);
	cnt += ft_print_width(flags.width, flags.prec, flags.zero);
	if (flags.minus == 0)
		cnt += ft_print_hex_part(flags, str_hex);
	return (cnt);
}

int				ft_print_hex(unsigned int value, int capital, t_flags flags)
{
	char	*str_hex;
	int		cnt;

	cnt = 0;
	if (flags.prec == 0 && value == 0)
	{
		cnt += ft_print_width(flags.width, 0, 0);
		return (cnt);
	}
	str_hex = ft_dec_to_hex(value);
	if (capital == 1)
		str_hex = ft_str_toupper(str_hex);
	cnt += ft_print_hex_order(flags, str_hex);
	free(str_hex);
	return (cnt);
}
