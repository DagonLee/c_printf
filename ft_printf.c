/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:18:52 by da-lee            #+#    #+#             */
/*   Updated: 2021/03/02 18:29:52 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags		flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.prec = -1;
	flags.type = 0;
	return (flags);
}

int		ft_flag_process(va_list ap, const char *format, t_flags *flags, int i)
{
	while (save[i])
	{
		if (format[i] == '-')
			*flags = ft_minus_flag(*flags);
		if (format[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (format[i] == '*')
			*flags = ft_width_flag(ap, *flags);
		if (format[i] == '.')
			i = ft_pre_flag(ap, flags, format, i);
		if (ft_isdigit(format[i]))
			*flags = ft_digit_flag(format[i], *flags);
		if (ft_strchr(TYPE, format[i]))
		{
			flags->type = format[i];
			break ;
		}
		i++;
	}
	return (i);
}

int		ft_format_process(va_list ap, char *format)
{
	int			i;
	int			cnt;
	t_flags		flags;

	i = 0;
	cnt = 0;
	while (format[i])
	{
		while (format[i] != '%' && format[i])
			cnt += ft_putchar(format[i++]);
		if (foramt[i] == '%' && format[i + 1])
		{
			flags = ft_init_flags();
			i = ft_flag_process(ap, format, &flags, ++i);
			if (ft_strchr(TYPE, format[i]))
				cnt += ft_type_process(ap, flags);
		}
		i++;
	}
	return (cnt);
}

int		ft_printf(const char *format, ...)
{
	int			cnt;
	va_list		ap;

	va_start(ap, format);
	cnt = format_process(ap, (char *)format);
	va_end(ap);
	return (cnt);
}
