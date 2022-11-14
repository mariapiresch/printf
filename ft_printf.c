/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapires- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:07:57 by mapires-          #+#    #+#             */
/*   Updated: 2022/11/14 10:08:00 by mapires-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

int ft_printf(char const *s_const, ...)
{
	char	c;
    va_list args;
	va_start(args, s_const);
	while (*s_const)
	{
		if (*s_const == '%')
		{
			if (*(s_const + 1) == 'c')
			{
				c = va_arg(args, char);
				write(1, &c, 1);
				s_const++;
			}
			else if (*(s_const + 1) == '%')
			{
				write(1, '%', 1);
				s_const++;
			}
		}
		else
			write(1, s_const, 1);
		s_const++;
	}
}

int main (void)
{
	ft_printf("Hola%c %%", 'r');
	return (0);
}