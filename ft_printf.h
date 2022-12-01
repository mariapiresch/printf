/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapires- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:08:04 by mapires-          #+#    #+#             */
/*   Updated: 2022/11/23 18:15:49 by mapires-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

int		ft_printf(char const *s_const, ...);
int		ft_conversions(char c, va_list args);
int		ft_printchar(char c);
int		ft_printstring(char *str);
void	ft_printnbr(long long nb, int bas, char *base, int *size);
void	ft_printun(size_t nb, int bas, char *base, int *size);

#endif
