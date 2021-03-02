/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:34:21 by da-lee            #+#    #+#             */
/*   Updated: 2021/03/02 18:56:56 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define TYPE "cspdiuxX%"

typedef struct	s_flags
{
	int			zero;
	int			minus;
	int			width;
	int			prec;
	char		type;
}				t_flags;

int		ft_flag_process(va_list ap, const char *format, t_flags *flags, int i)
int		ft_format_process(va_list ap, char *format)
int		ft_printf(const char *format, ...)
t_flags	ft_init_flags(void)

#endif
