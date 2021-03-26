/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_maj_uhexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:26:46 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/25 16:27:44 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_upper_and_print(char *strn, int len, t_info *info)
{
	int	i;

	i = -1;
	while (strn[++i])
		strn[i] = ft_toupper(strn[i]);
	if (len < info->field)
		ft_print_with_field(strn, len, info);
	else
		ft_putstr_printed(strn, info);
	free(strn);
}

int	ft_print_maj_uhexa(unsigned int n, t_info *info)
{
	char	*strn;
	int		len;

	if (n == 0 && info->prec == 0)
	{
		if (ft_salloc(&strn, sizeof(char)))
			return (-1);
		strn[0] = 0;
	}
	else
		strn = ft_itoa_hexa(n);
	len = ft_strlen(strn);
	if (len < info->prec)
	{
		strn = ft_str_prec(strn, len, info->prec);
		len = ft_strlen(strn);
	}
	if (strn == NULL)
		return (-1);
	ft_upper_and_print(strn, len, info);
	return (1);
}
