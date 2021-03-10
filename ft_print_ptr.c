/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:30:50 by da-lee            #+#    #+#             */
/*   Updated: 2021/03/10 11:19:32 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*insert_hex(unsigned long long save,
char *ret, int cnt)
{
	while (save != 0)
	{
		if ((save % 16) < 10)
			ret[cnt - 1] = (save % 16) + 48;
		else
			ret[cnt - 1] = (save % 16) + 87;
		save /= 16;
		cnt--;
	}
	return (ret);
}

char		*ft_dec_to_hex(unsigned long long ull)
{
	char				*ret;
	unsigned long long	save;
	int					cnt;

	ret = 0;
	cnt = 0;
	save = ull;
	if (ull == 0)
		return (ft_strdup("0"));
	while (ull != 0)
	{
		ull /= 16;
		cnt++;
	}
	if (!(ret = malloc(sizeof(char) * (cnt + 1))))
		return (0);
	ret[cnt] = '\0';
	ret = insert_hex(save, ret, cnt);
	return (ret);
}

int			ft_print_ptr_part(char *ptr, t_flags flags)
{
	int cnt;

	cnt = 0;
	cnt += ft_putstr("0x", 2);
	if (flags.prec >= 0)
	{
		cnt += ft_print_width(flags.prec, ft_strlen(ptr), 0);
		cnt += ft_putstr(ptr, flags.prec);
	}
	else
		cnt += ft_putstr(ptr, ft_strlen(ptr));
	return (cnt);
}

int			ft_print_none(t_flags flags)
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

int			ft_print_ptr(unsigned long long value, t_flags flags)
{
	char	*ptr;
	int		cnt;

	cnt = 0;
	if (value == 0 && flags.prec == 0)
	{
		cnt += ft_print_none(flags);
		return (cnt);
	}
	ptr = ft_dec_to_hex(value);
	if (flags.prec < ft_strlen(ptr))
		flags.prec = ft_strlen(ptr);
	if (flags.minus == 1)
		cnt += ft_print_ptr_part(ptr, flags);
	cnt += ft_print_width(flags.width, ft_strlen(ptr) + 2, 0);
	if (flags.minus == 0)
		cnt += ft_print_ptr_part(ptr, flags);
	free(ptr);
	return (cnt);
}
