/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:43:33 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/25 16:20:46 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_prec_and_print_int(char *snbr, int len, t_info *info)
{
	if (len <= info->prec)
	{
		snbr = ft_str_prec(snbr, len, info->prec);
		len = ft_strlen(snbr);
	}
	if (snbr == NULL)
		return (-1);
	if (len < info->field)
		ft_print_with_field(snbr, len, info);
	else
		ft_putstr_printed(snbr, info);
	free(snbr);
	return (1);
}

int	ft_print_int(int nbr, t_info *info)
{
	char	*snbr;
	int		len;
	long	nb;

	nb = nbr;
	if (nb < 0 && info->zero == 1)
	{
		nb = (long)nb * -1;
		write(1, "-", 1);
		info->printed++;
		len = 1;
	}
	else
		len = 0;
	if (nb == 0 && info->prec == 0)
	{
		if (ft_salloc(&snbr, sizeof(char)))
			return (-1);
		snbr[0] = 0;
	}
	else
		snbr = ft_itoa(nb);
	len = len + ft_strlen(snbr);
	return (ft_prec_and_print_int(snbr, len, info));
}
