/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:30:50 by da-lee            #+#    #+#             */
/*   Updated: 2021/03/08 21:31:48 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*treat_base(unsigned long long ull_save, int base,
char *rtn, int count)
{
	while (ull_save != 0)
	{
		if ((ull_save % base) < 10)
			rtn[count - 1] = (ull_save % base) + 48;
		else
			rtn[count - 1] = (ull_save % base) + 87;
		ull_save /= base;
		count--;
	}
	return (rtn);
}

char		*ft_ull_base(unsigned long long ull, int base)
{
	char				*rtn;
	unsigned long long	ull_save;
	int					count;

	rtn = 0;
	count = 0;
	ull_save = ull;
	if (ull == 0)
		return (ft_strdup("0"));
	while (ull != 0)
	{
		ull /= base;
		count++;
	}
	if (!(rtn = malloc(sizeof(char) * (count + 1))))
		return (0);
	rtn[count] = '\0';
	rtn = treat_base(ull_save, base, rtn, count);
	return (rtn);
}

int			ft_in_put_part_pointer(char *pointer, t_flags flags)
{
	int char_count;

	char_count = 0;
	char_count += ft_putstr("0x", 2);
	if (flags.prec >= 0)
	{
		char_count += ft_print_width(flags.prec, ft_strlen(pointer), 0);
		char_count += ft_putstr(pointer, flags.prec);
	}
	else
		char_count += ft_putstr(pointer, ft_strlen(pointer));
	return (char_count);
}

int			ft_print_null(t_flags flags)
{
	int cnt;

	cnt = 0;
	if (flags.minus == 1)
	{
		cnt += ft_putstr("0x", 2);
		return (cnt += ft_print_width(flags.width, 2, 0));
	}
	else
	{
		cnt += ft_print_width(flags.width, 2, 0);
		return (cnt += ft_putstr("0x", 2));
	}
}

int			ft_print_ptr(unsigned long long ull, t_flags flags)
{
	char	*ptr;
	int		cnt;

	cnt = 0;
	if (ull == 0 && flags.prec == 0)
	{
		cnt += ft_print_null(flags);
		return (cnt);
	}
	ptr = ft_ull_base(ull, 16);
	if (flags.prec < ft_strlen(ptr))
		flags.prec = ft_strlen(ptr);
	if (flags.minus == 1)
		cnt += ft_in_put_part_pointer(ptr, flags);
	cnt += ft_print_width(flags.width, ft_strlen(ptr) + 2, 0);
	if (flags.minus == 0)
		cnt += ft_in_put_part_pointer(ptr, flags);
	free(ptr);
	return (cnt);
}
