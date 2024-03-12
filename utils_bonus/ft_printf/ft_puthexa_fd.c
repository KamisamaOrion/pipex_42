/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:16:46 by mhervoch          #+#    #+#             */
/*   Updated: 2023/11/27 14:16:47 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_verif_base(char *base)
{
	int		len_base;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 1;
	str = base;
	len_base = ft_strlen(base);
	if (len_base == 0 || len_base == 1)
		return (0);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		while (base[j])
		{
			if (base[j] == str[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_verif_nbr(unsigned long nbr)
{
	int	len;

	if (nbr == 0)
	{
		len = write(1, "(nil)", 5);
		return (len);
	}
	len = write(1, "0x", 2);
	return (len);
}

int	ft_puthexa_base(unsigned int nbr, char *base, int size)
{
	unsigned long	len_base;
	unsigned long	divided;
	unsigned long	modulo;

	if (ft_verif_base(base) == 0)
		return (0);
	len_base = ft_strlen(base);
	if (nbr < len_base)
	{
		size++;
		write(1, &base[nbr], 1);
		return (size);
	}
	divided = nbr / len_base;
	modulo = nbr % len_base;
	size = ft_puthexa_base(divided, base, size);
	size++;
	write(1, &base[modulo], 1);
	return (size);
}

int	ft_putbase(unsigned long nbr, char *base, int size)
{
	unsigned long	len_base;
	unsigned long	divided;
	unsigned long	modulo;

	if (ft_verif_base(base) == 0)
		return (0);
	len_base = ft_strlen(base);
	if (nbr < len_base)
	{
		size++;
		write(1, &base[nbr], 1);
		return (size);
	}
	divided = nbr / len_base;
	modulo = nbr % len_base;
	size = ft_putbase(divided, base, size);
	size++;
	write(1, &base[modulo], 1);
	return (size);
}
