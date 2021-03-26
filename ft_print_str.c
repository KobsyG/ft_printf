/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:15:01 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/25 12:52:34 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(const char *s, t_info *info)
{
	int		len;
	char	*s2;
	char	*tmp;

	if (s == NULL)
		s2 = ft_strdup("(null)");
	else
		s2 = ft_strdup(s);
	len = ft_strlen(s2);
	if (info->prec != -1 && len > info->prec)
	{
		tmp = s2;
		s2 = ft_substr(tmp, 0, info->prec);
		free(tmp);
		len = ft_strlen(s2);
	}
	if (s2 == NULL)
		return (-1);
	if (len < info->field)
		ft_print_with_field(s2, len, info);
	else
		ft_putstr_printed(s2, info);
	free(s2);
	return (1);
}
