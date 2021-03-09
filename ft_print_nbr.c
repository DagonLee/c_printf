/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:43:16 by da-lee            #+#    #+#             */
/*   Updated: 2021/03/09 13:18:34 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_in_put_part_int(char *d_i, int save_i, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (save_i < 0 && flags.prec >= 0)
		ft_putchar('-');
	if (flags.prec >= 0)
		char_count += ft_print_width(flags.prec - 1, ft_strlen(d_i) - 1, 1);
	char_count += ft_putstr(d_i, ft_strlen(d_i));
	return (char_count);
}

static int	ft_put_part_int(char *d_i, int save_i, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_in_put_part_int(d_i, save_i, flags);
	if (flags.prec >= 0 && flags.prec < ft_strlen(d_i))
		flags.prec = ft_strlen(d_i);
	if (flags.prec >= 0)
	{
		flags.width -= flags.prec;
		char_count += ft_print_width(flags.width, 0, 0);
	}
	else
		char_count += ft_print_width(flags.width, ft_strlen(d_i), flags.zero);
	if (flags.minus == 0)
		char_count += ft_in_put_part_int(d_i, save_i, flags);
	return (char_count);
}

int			ft_print_int(int i, t_flags flags)
{
	char	*d_i;
	int		save;
	int		cnt;

	save = i;
	cnt = 0;
	if (flags.prec == 0 && i == 0)
	{
		cnt += ft_print_width(flags.width, 0, 0);
		return (cnt);
	}
	if (i < 0 && (flags.prec >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.prec <= -1)
			ft_putstr("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		cnt++;
	}
	d_i = ft_itoa(i);
	cnt += ft_put_part_int(d_i, save, flags);
	free(d_i);
	return (cnt);
}
