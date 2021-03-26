/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:01:28 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/25 12:50:00 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c, t_info *info)
{
	if (info->field > 1)
	{
		if (info->minus == 0)
		{
			if (info->zero)
				ft_compl(info->field - 1, '0', info);
			else
				ft_compl(info->field - 1, ' ', info);
		}
		write(1, &c, 1);
		if (info->minus == 1)
			ft_compl(info->field - 1, ' ', info);
	}
	else
		write(1, &c, 1);
	info->printed++;
	return (1);
}
