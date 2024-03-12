/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:04:25 by mhervoch          #+#    #+#             */
/*   Updated: 2023/11/22 21:34:42 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_intlen(int n)
{
	int	size;

	size = 0;
	while (n >= 10)
	{
		size++;
		n = n / 10;
	}
	size++;
	return (size);
}

int	ft_convertion(char c, va_list lst)
{
	int				res;
	unsigned long	n;

	if (c == 'd' || c == 'i')
		res = ft_putnbr_fd(va_arg(lst, int), 1, 0);
	else if (c == 'c')
		res = ft_putchar_fd(va_arg(lst, int), 1);
	else if (c == 's')
		res = ft_putstr_fd(va_arg(lst, char *), 1);
	else if (c == '%')
		res = ft_putchar_fd(c, 1);
	else if (c == 'x')
		res = ft_puthexa_base(va_arg(lst, unsigned int), "0123456789abcdef", 0);
	else if (c == 'X')
		res = ft_puthexa_base(va_arg(lst, unsigned int), "0123456789ABCDEF", 0);
	else if (c == 'p')
	{
		n = va_arg(lst, unsigned long);
		res = ft_verif_nbr(n);
		if (res != 5)
			res += ft_putbase(n, "0123456789abcdef", 0);
	}
	else if (c == 'u')
		res = ft_puthexa_base(va_arg(lst, unsigned int), "0123456789", 0);
	return (res);
}

int	ft_printf(const char *f, ...)
{
	int		i;
	va_list	lst;
	int		size;

	i = -1;
	size = 0;
	if (!f)
		return (-1);
	va_start(lst, f);
	while (f[++i])
	{
		if (f[i] == '%' && ft_isconv(f[i + 1]))
		{
			size += ft_convertion(f[i + 1], lst);
			i++;
		}
		else if (f[i] == '%' && f[i + 1] == 0)
			size = -1;
		else
		{
			ft_putchar_fd(f[i], 1);
			size++;
		}
	}
	return (size);
}
