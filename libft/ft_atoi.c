/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: da-lee <da-lee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:16:32 by da-lee            #+#    #+#             */
/*   Updated: 2020/11/10 19:14:43 by da-lee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\v' || c == '\r' || c == '\t' ||
		c == '\f' || c == '\n')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	unsigned int	i;
	long			result;
	int				negative;

	i = 0;
	negative = 1;
	result = 0;
	while (str[i] && ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > 2147483647 && negative == 1)
			return (-1);
		if (result > 2147483648 && negative == -1)
			return (0);
		i++;
	}
	return (result * negative);
}
