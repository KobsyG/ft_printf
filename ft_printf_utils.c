/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:14:39 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/25 11:14:15 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->zero = 0;
	info->minus = 0;
	info->field = 0;
	info->prec = -1;
}

int	is_conv(char c)
{
	char	*conv;
	int		i;

	conv = CONV;
	i = 0;
	while (conv[i])
	{
		if (c == conv[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_attr(char c)
{
	char	*attr;
	int		i;

	attr = ATTR;
	i = 0;
	while (attr[i])
	{
		if (c == attr[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_compl(int n, char c, t_info *info)
{
	info->printed = info->printed + n;
	while (--n >= 0)
		write(1, &c, 1);
}
