/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:16:57 by mhervoch          #+#    #+#             */
/*   Updated: 2023/11/27 14:16:59 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd, int len);
int		ft_putstr_fd(char *s, int fd);
int		ft_isconv(int c);
size_t	ft_strlen(const char *s);
int		ft_put_unsigned_nbr_fd(unsigned int n, int fd, int len);
int		ft_puthexa_base(unsigned int nbr, char *base, int size);
int		ft_printf(const char *f, ...);
int		ft_putbase(unsigned long nbr, char *base, int size);
int		ft_verif_nbr(unsigned long nbr);

#endif
