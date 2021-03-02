/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:07:07 by da-lee            #+#    #+#             */
/*   Updated: 2021/03/02 19:13:41 by da-lee           ###   ########.fr       */
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
}

t_flags		ft_digit_flag(char c, t_flags flags)
{
}

int			ft_pre_flag(va_list ap, t_flags *flags, const char *format)
{
}
