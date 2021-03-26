/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeco <gbeco@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:12:40 by gbeco             #+#    #+#             */
/*   Updated: 2021/03/26 08:09:18 by gbeco            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# define CONV "cspdiuxX%n"
# define ATTR "-0"

typedef struct s_info
{
	int		zero;
	int		minus;
	int		field;
	int		prec;
	char	conv;
	int		printed;
}				t_info;

char	*ft_itoa_hexa(unsigned long long n);
char	*ft_str_prec(char *s, int len, int prec);

int		complete_info(char *form, t_info *info, va_list ap);
int		ft_field(char *form, t_info *info, va_list ap);
int		ft_form(const char *s, t_info *info, va_list ap);
int		ft_prec(char *s, t_info *info, va_list ap);
int		ft_print(t_info *info, va_list ap);
int		ft_print_char(int c, t_info *info);
int		ft_print_int(int nbr, t_info *info);
int		ft_print_maj_uhexa(unsigned int n, t_info *info);
int		ft_print_ptr(void *ptr, t_info *info);
int		ft_print_str(const char *s, t_info *info);
int		ft_print_uhexa(unsigned int n, t_info *info);
int		ft_print_uint(unsigned int n, t_info *info);
int		ft_printf(const char *s, ...) __attribute__ ((format(printf, 1, 2)));
int		is_attr(char c);
int		is_conv(char c);
int		is_digit(char c);

void	ft_compl(int n, char c, t_info *info);
void	ft_print_with_field(char *s, int len, t_info *info);
void	ft_putstr_printed(char *s, t_info *info);
void	init_info(t_info *info);
void	verif_ignored(t_info *info);

#endif