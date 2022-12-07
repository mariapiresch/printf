/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapires- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:43:01 by mapires-          #+#    #+#             */
/*   Updated: 2022/12/01 17:43:08 by mapires-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchar(char c, int *size)
{
	*size = write(1, &c, 1);
}

void	ft_printstring(char *str, int *size)
{
	if (!str)
		*size = write(1, "(null)", 6);
	else
		while (str[*size])
			*size += write(1, &str[*size], 1);
}

void	ft_printnbr(long long nb, char *base, int *size)
{
	if (nb < 0)
	{
		*size += write(1, "-", 1);
		nb *= -1;
	}
	if (nb < 10)
	{
		*size += write(1, &base[nb], 1);
		return ;
	}
	else
		ft_printnbr(nb / 10, base, size);
	*size += write(1, &base[nb % 10], 1);
}

void	ft_printun(size_t nb, int bas, char *base, int *size)
{
	if (nb < (size_t)bas)
	{
		*size += write(1, &base[nb], 1);
		return ;
	}
	else
		ft_printun(nb / bas, bas, base, size);
	*size += write(1, &base[nb % bas], 1);
}
