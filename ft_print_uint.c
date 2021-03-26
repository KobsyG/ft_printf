/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:24:48 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/25 13:02:11 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbrdigit(unsigned int n)
{
	int	len;

	if (n <= 0)
	{
		len = 1;
		n = n * -1;
	}
	else
		len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*nbr;

	len = nbrdigit(n);
	if (ft_salloc(&nbr, sizeof(char) * (len + 1)))
		return (NULL);
	if (n == 0)
		nbr[0] = '0';
	nbr[len] = 0;
	while (n > 0)
	{
		nbr[--len] = (n % 10) + 48;
		n = n / 10;
	}
	return (nbr);
}

int	ft_print_uint(unsigned int n, t_info *info)
{
	char	*sn;
	int		len;

	if (n == 0 && info->prec == 0)
	{
		if (ft_salloc(&sn, sizeof(char)))
			return (-1);
		sn[0] = 0;
	}
	else
		sn = ft_uitoa(n);
	len = ft_strlen(sn);
	if (len < info->prec)
	{
		sn = ft_str_prec(sn, len, info->prec);
		len = ft_strlen(sn);
	}
	if (sn == NULL)
		return (-1);
	if (len < info->field)
		ft_print_with_field(sn, len, info);
	else
		ft_putstr_printed(sn, info);
	free(sn);
	return (1);
}
