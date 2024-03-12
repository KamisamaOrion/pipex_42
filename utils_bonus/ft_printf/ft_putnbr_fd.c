/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:03:38 by mhervoch          #+#    #+#             */
/*   Updated: 2023/11/09 15:37:07 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd, int len)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		len = 11;
	}
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
			len++;
		}
		if (n >= 10)
			len = ft_putnbr_fd(n / 10, fd, (len + 1));
		else
			len++;
		write (fd, &(char){n % 10 + 48}, 1);
	}
	return (len);
}

int	ft_put_unsigned_nbr_fd(unsigned int n, int fd, int len)
{
	if (n >= 10)
	{
		len += ft_put_unsigned_nbr_fd(n / 10, fd, len);
	}
	else
		len++;
	write (fd, &(unsigned char){n % 10 + 48}, 1);
	return (len);
}
