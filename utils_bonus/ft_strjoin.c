/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:57:47 by mhervoch          #+#    #+#             */
/*   Updated: 2024/03/31 22:27:03 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(s3))
		return (NULL);
	ft_memmove(s3, s1, ft_strlen(s1));
	ft_memmove(s3 + ft_strlen(s1), s2, ft_strlen(s2));
	s3[ft_strlen(s1) + ft_strlen(s2)] = 0;
	return (s3);
}
