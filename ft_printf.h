/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:34:21 by da-lee            #+#    #+#             */
/*   Updated: 2021/03/10 11:01:22 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define TYPE "cspdiuxX%"

typedef struct	s_flags
{
	int			zero;
	int			minus;
	int			width;
	int			prec;
	int			ast;
	char		type;
}				t_flags;

int				ft_flag_process(va_list ap, const char *f, t_flags *fl, int i);
int				ft_format_process(va_list ap, char *format);
int				ft_printf(const char *format, ...);
int				ft_prec_flag(va_list ap, t_flags *flags, const char *f, int s);
t_flags			ft_digit_flag(char c, t_flags flags);
t_flags			ft_width_flag(va_list ap, t_flags flags);
t_flags			ft_minus_flag(t_flags flags);
int				ft_type_process(va_list ap, t_flags flags);
int				ft_print_width(int width, int minus, int zero);
int				ft_print_char(char c, t_flags flags);
int				ft_print_str(char *str, t_flags flags);
int				ft_print_percent(t_flags flags);
int				ft_print_ptr(unsigned long long ull, t_flags flags);
int				ft_print_int(int i, t_flags flags);
char			*ft_dec_to_hex(unsigned long long ull);
int				ft_print_hex(unsigned int ui, int lower, t_flags flags);
int				ft_print_uint(unsigned int n, t_flags flags);
#endif
