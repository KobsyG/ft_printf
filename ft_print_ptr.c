/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:21:15 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/25 15:21:24 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_char_hexa(unsigned long long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

char	*ft_itoa_hexa(unsigned long long n)
{
	int		len;
	char	*nbr;
	char	*hexa;

	hexa = "0123456789abcdef";
	len = nbr_char_hexa(n);
	if (ft_salloc(&nbr, sizeof(char) * (len + 1)))
		return (NULL);
	if (n == 0)
		nbr[0] = '0';
	else if (n < 0)
	{
		nbr[0] = '-';
		n = -n;
	}
	nbr[len] = 0;
	while (n > 0)
	{
		nbr[--len] = hexa[n % 16];
		n = n / 16;
	}
	return (nbr);
}

static char	*ft_add_0x(char *sptr)
{
	char	*new;
	int		i;

	if (!sptr)
		return (NULL);
	if (ft_salloc(&new, ft_strlen(sptr) + 3))
		return (NULL);
	new[0] = '0';
	new[1] = 'x';
	i = -1;
	while (sptr[++i])
		new[i + 2] = sptr[i];
	new[i + 2] = 0;
	free(sptr);
	return (new);
}

int	ft_print_ptr(void *ptr, t_info *info)
{
	char	*sptr;
	int		len;

	sptr = ft_itoa_hexa((unsigned long long)ptr);
	len = ft_strlen(sptr);
	if (len < info->prec)
	{
		sptr = ft_str_prec(sptr, len, info->prec);
		len = ft_strlen(sptr);
	}
	sptr = ft_add_0x(sptr);
	if (sptr == NULL)
		return (-1);
	len = len + 2;
	if (len < info->field)
		ft_print_with_field(sptr, len, info);
	else
		ft_putstr_printed(sptr, info);
	free(sptr);
	return (1);
}
