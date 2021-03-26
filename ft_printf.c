/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:13:18 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/26 07:58:16 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write(char c, t_info *info)
{
	write(1, &c, 1);
	info->printed++;
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	t_info	info;
	int		i;

	va_start(ap, s);
	i = 0;
	info.printed = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			init_info(&info);
			i = ft_form(&s[i + 1], &info, ap) + i;
			if (i == -1 || ft_print(&info, ap) == -1)
				return (-1);
		}
		if (s[i] && s[i] != '%')
		{
			ft_write(s[i], &info);
			i++;
		}
	}
	va_end(ap);
	return (info.printed);
}

int	ft_print(t_info *info, va_list ap)
{
	if (info->conv == 'd' || info->conv == 'i')
		return (ft_print_int(va_arg(ap, int), info));
	else if (info->conv == 'c')
		return (ft_print_char(va_arg(ap, int), info));
	else if (info->conv == 's')
		return (ft_print_str(va_arg(ap, char *), info));
	else if (info->conv == 'p')
		return (ft_print_ptr(va_arg(ap, void *), info));
	else if (info->conv == 'u')
		return (ft_print_uint(va_arg(ap, unsigned int), info));
	else if (info->conv == 'x')
		return (ft_print_uhexa(va_arg(ap, unsigned int), info));
	else if (info->conv == 'X')
		return (ft_print_maj_uhexa(va_arg(ap, unsigned int), info));
	else if (info->conv == '%')
		return (ft_print_char('%', info));
	else if (info->conv == 'n')
		*(va_arg(ap, int*)) = info->printed;
	return (1);
}

void	ft_print_with_field(char *s, int len, t_info *info)
{
	if (info->minus == 1)
	{
		ft_putstr_printed(s, info);
		ft_compl(info->field - len, ' ', info);
	}
	else if (info->zero == 1)
	{
		ft_compl(info->field - len, '0', info);
		ft_putstr_printed(s, info);
	}
	else
	{
		ft_compl(info->field - len, ' ', info);
		ft_putstr_printed(s, info);
	}
}

void	ft_putstr_printed(char *s, t_info *info)
{
	int	i;

	i = -1;
	while (s[++i])
		ft_putchar_fd(s[i], 1);
	info->printed = info->printed + i;
}
