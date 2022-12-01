/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapires- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:07:57 by mapires-          #+#    #+#             */
/*   Updated: 2022/11/23 18:14:21 by mapires-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversions(char c, va_list args)
{
	int		size;

	size = 0;
	if (c == 'c')
		size = ft_printchar(va_arg(args, int));
	else if (c == 's')
		size = ft_printstring(va_arg(args, char *));
	else if (c == 'p')
	{
		size = write(1, "0x", 2);
		ft_printun((size_t)va_arg(args, void *), 16, "0123456789abcdef", &size);
	}
	else if (c == 'd' || c == 'i')
		ft_printnbr(va_arg(args, int), 10, "0123456789", &size);
	else if (c == 'u')
		ft_printun(va_arg(args, unsigned), 10, "0123456789", &size);
	else if (c == 'x')
		ft_printun(va_arg(args, unsigned), 16, "0123456789abcdef", &size);
	else if (c == 'X')
		ft_printun(va_arg(args, unsigned), 16, "0123456789ABCDEF", &size);
	else if (c == '%')
		size = write(1, "%", 1);
	return (size);
}

int	ft_printf(char const *s_const, ...)
{
	va_list	args;
	int		size;

	size = 0;
	va_start(args, s_const);
	while (*s_const)
	{
		if (*s_const == '%')
		{
			s_const++;
			size += ft_conversions(*s_const, args);
		}
		else
			size += write(1, s_const, 1);
		s_const++;
	}
	va_end(args);
	return (size);
}

/*int	main(void)
{
	char	c = 'r';	
	int	*str;

	*str = 3;
	ft_printf("%d", ft_printf("Hola %p %p", (void *) LONG_MIN, (void *)LONG_MAX));
	write(1, "\n", 1);
	printf("%d", printf("Hola %p %p", (void *) LONG_MIN, (void *)LONG_MAX));
	return (0);
}
*/