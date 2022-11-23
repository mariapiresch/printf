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

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstring(char *str)
{
	int	size;

	size = 0;
	while (str[size])
	{
		write(1, &str[size], 1);
		size++;
	}
	return (size);
}

/*void	ft_printptr(void *ptr)
{
	int	i;

	i = ptr;
	while()
}

void	ft_printhexa(int i)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	while (i)
	{
		
	}
}*/

int	ft_lennbr(long long nbr, int bas)
{
	int	size;

	size = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		size++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= bas;
		size++;
	}
	return (size);
}

void	ft_putnbr(long long nb, int bas, char *base)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb < bas)
	{
		write(1, &base[nb], 1);
		return ;
	}
	else
		ft_putnbr(nb / bas, bas, base);
	write(1, &base[nb % bas], 1);
}

int	ft_printnbr(int nbr, int bas, char *base)
{
	ft_putnbr((long long)nbr, bas, base);
	return (ft_lennbr((long long)nbr, bas));
}

int	ft_conversions(char c, va_list args)
{
	int	size;

	size = 0;
	if (c == 'c')
		size = ft_printchar(va_arg(args, int));
	else if (c == 's')
		size = ft_printstring(va_arg(args, char *));
/*	else if (c == 'p')
		size = ft_printptr(va_arg(args, void *));*/
	else if (c == 'd' || c == 'i')
		size = ft_printnbr(va_arg(args, int), 10, "0123456789");
	else if (c == 'x')
		size = ft_printnbr(va_arg(args, int), 16, "0123456789abcdef");
	else if (c == 'X')
		size = ft_printnbr(va_arg(args, int), 16, "0123456789ABCDEF");
	else if (c == '%')
	{
		write(1, "%", 1);
		size++;
	}
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
			ft_conversions(*s_const, args);
		}
		else
		{
			write(1, s_const, 1);
			size++;
		}
		s_const++;
	}
	va_end(args);
	return (size);
}

/*int	main(void)
{
	char	c = 'r';
	char	*str = "adiós \n";

	ft_printf("Hola\n%c %s %d %i %x %X %%", c, str, -15, -15, -15, -15);
	//Arreglar los números hexadecimales negativos!!!!!!
	write(1, "\n", 1);
	printf("Hola\n%c %s %d %i %x %X %%", c, str, -15, -15, -15, -15);
	return (0);
}*/
