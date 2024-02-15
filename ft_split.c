/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:42:56 by mhervoch          #+#    #+#             */
/*   Updated: 2024/01/23 23:15:56 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_countwords(char *s, char c)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	if (!*s)
		return (cpt);
	if (s[0] != c)
		cpt++;
	i++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			cpt++;
		i++;
	}
	return (cpt);
}

static int	ft_len_word(char	*s, char c, int pos)
{
	int	cpt;
	int	i;

	i = pos;
	cpt = 0;
	while (!(s[i] == c) && s[i])
	{
		cpt++;
		i++;
	}
	return (cpt);
}

static void	ft_free_all(char	**s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i]);
	free(s);
}

static char	*ft_case(int *k, char *s1, char c)
{
	char	*s2;

	while (s1[*k] == c)
		*k += 1;
	s2 = malloc(sizeof(char) * (ft_len_word(s1, c, *k) + 1));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1 + *k, ft_len_word(s1, c, *k) + 1);
	*k += ft_len_word(s1, c, *k);
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	int		i;	
	char	*s1;
	char	**s2;
	int		k;

	k = 0;
	i = 0;
	if (!s)
		return (NULL);
	s1 = (char *)s;
	s2 = malloc(sizeof(char *) * (ft_countwords(s1, c) + 1));
	while (s2 && *s1 && i < ft_countwords(s1, c))
	{
		s2[i] = ft_case(&k, s1, c);
		if (!s2[i])
		{
			ft_free_all(s2);
			return (NULL);
		}
		i++;
	}
	if (s2)
		s2[i] = NULL;
	return (s2);
}
