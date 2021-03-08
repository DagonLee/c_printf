/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:13:56 by da-lee            #+#    #+#             */
/*   Updated: 2021/03/08 13:54:00 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_process(va_list ap, t_flags flags)
{
	char c = flags.type;
	int cnt;

	cnt = 0;
	if (c == 'c')
		cnt = ft_print_char(va_arg(ap, int), flags);
	else if (c == 's')
		cnt = ft_print_str(va_arg(ap, char *), flags);
//	else if (c == 'p')
//		cnt = ft_print_ptr(va_arg(ap, unsigned long long), flags);
//	else if (c == 'd' || c == 'i')
//		cnt = ft_print_int(va_arg(args, int), flags);
//	else if (c == 'u')
//		cnt += ft_print_uint((unsigned int)va_arg(args, unsigned int),
//		flags);
//	else if (c == 'x')
//		cnt += ft_print_hexa(va_arg(args, unsigned int), 1, flags);
//	else if (c == 'X')
//		cnt += ft_print_hexa(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		cnt += ft_print_percent(flags);
	return (cnt);
}
