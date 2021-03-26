/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:18:38 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/26 07:58:34 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_field(char *form, t_info *info, va_list ap)
{
	int		i;
	int		j;
	char	*field;

	i = 0;
	if (form[i] == '*')
	{
		info->field = va_arg(ap, int);
		return (1);
	}
	while (is_digit(form[i]))
		i++;
	if (ft_salloc(&field, sizeof(char) * (i + 1)))
		return (-1);
	field[i] = 0;
	j = i;
	while (--j >= 0)
		field[j] = form[j];
	info->field = ft_atoi(field);
	free(field);
	return (i);
}

int	ft_prec(char *s, t_info *info, va_list ap)
{
	int		i;
	int		j;
	char	*prec;

	i = 0;
	if (s[i] == '*')
	{
		info->prec = va_arg(ap, int);
		return (1);
	}
	while (is_digit(s[i]) == 1)
		i++;
	if (ft_salloc(&prec, sizeof(char) * (i + 1)))
		return (-1);
	prec[i] = 0;
	j = i;
	while (--j >= 0)
		prec[j] = s[j];
	info->prec = ft_atoi(prec);
	free(prec);
	return (i);
}

int	complete_info(char *form, t_info *info, va_list ap)
{
	int	i;

	i = -1;
	while (is_attr(form[++i]))
	{
		if (form[i] == '0')
			info->zero = 1;
		if (form[i] == '-')
			info->minus = 1;
	}
	i = ft_field(&form[i], info, ap) + i;
	if (i == -1)
		return (-1);
	if (form[i] == '.')
		i = ft_prec(&form[i + 1], info, ap);
	return (i);
}

void	verif_ignored(t_info *info)
{
	if (info->field < 0)
	{
		info->field = -info->field;
		info->minus = 1;
	}
	if (info->prec < -1)
		info->prec = -1;
	if (info->minus == 1 || info->prec != -1)
		info->zero = 0;
}

int	ft_form(const char *s, t_info *info, va_list ap)
{
	int		i;
	int		ret;
	char	*form;

	i = 0;
	while (is_conv(s[i]) == 0)
		i++;
	ret = i + 2;
	info->conv = s[i];
	if (ft_salloc(&form, sizeof(char) * (i + 1)))
		return (-1);
	form[i] = 0;
	while (i-- > 0)
		form[i] = s[i];
	if (complete_info(form, info, ap) == -1)
	{
		free(form);
		return (-1);
	}
	verif_ignored(info);
	free(form);
	return (ret);
}
