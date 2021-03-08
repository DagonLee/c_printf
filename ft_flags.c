/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:07:07 by da-lee            #+#    #+#             */
/*   Updated: 2021/03/08 14:53:19 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		ft_minus_flag(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags		ft_width_flag(va_list ap, t_flags flags)
{
	flags.ast = 1;
	flags.width = va_arg(ap, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.zero = 0;
		flags.width *= -1;
	}
	return (flags);
}

t_flags		ft_digit_flag(char c, t_flags flags)
{
	if (flags.ast == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

int			ft_prec_flag(va_list ap, t_flags *flags, const char *format, int s)
{
	int i;

	i = s + 1;
	if (format[i] == '*')
	{
		flags->prec = va_arg(ap, int);
		i++;
	}
	else
	{
		flags->prec = 0;
		while (ft_isdigit(format[i]))
			flags->prec = (flags->prec * 10) + (format[i++] - '0');
	}
	return (i);
}
