/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:51:01 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/25 16:27:29 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*add_prec_neg(char *s, int len, int prec)
{
	char	*new;
	int		i;
	int		j;
	int		diff;

	diff = prec - len;
	if (ft_salloc(&new, sizeof(char) * (prec + 2)))
	{
		free(s);
		return (NULL);
	}
	new[0] = '-';
	i = 0;
	j = 0;
	while (i++ <= diff)
		new[i] = '0';
	i--;
	while (s[++j])
		new[i + j] = s[j];
	new[i + j] = 0;
	free(s);
	return (new);
}

char	*ft_str_prec(char *s, int len, int prec)
{
	char	*new;
	int		i;
	int		j;
	int		diff;

	if (!s)
		return (NULL);
	diff = prec - len;
	if (s[0] == '-')
		return (add_prec_neg(s, len, prec));
	else
	{
		if (ft_salloc(&new, sizeof(char) * (prec + 1)))
			return (NULL);
		i = -1;
		j = -1;
		while (++i < diff)
			new[i] = '0';
		while (s[++j])
			new[i + j] = s[j];
		new[i + j] = 0;
		free(s);
		return (new);
	}
}
