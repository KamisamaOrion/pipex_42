/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:38:36 by mhervoch          #+#    #+#             */
/*   Updated: 2023/11/16 19:03:38 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isconv(int c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'p' \
			||c == 'c' || c == 's' || c == 'x' || c == 'X' || c == '%');
}
