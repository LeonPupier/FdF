/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:52:33 by lpupier           #+#    #+#             */
/*   Updated: 2022/12/02 16:00:33 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

//ft_printf.c
int		ft_printf(const char *format, ...);

// ft_functions.c
void	ft_putchar_p(char c, int *count);
void	ft_putstr_p(char *str, int *count);

// ft_display_arg.c
void	ft_display_arg(char c, va_list ap, int *count);

// ft_putnbr_base.c
void	ft_putnbr_base(long long unsigned int nbr, long long unsigned int size,
			char *base, int *count);
void	ft_putnbr(int nbr, int *count);

#endif