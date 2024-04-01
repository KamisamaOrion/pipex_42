/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:53:25 by mhervoch          #+#    #+#             */
/*   Updated: 2024/04/01 21:37:33 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free_double(void **s1, void **s2)
{
	ft_free_tab((void **) s1);
	ft_free_tab((void **) s2);
}

int	ft_strlen_free(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	free(s);
	return (i);
}

char	*grep(char **env)
{
	char	*path;
	int		i;

	i = 0;
	if (!env[i])
		return (ft_strdup(""));
	while (env[i] && strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (ft_strdup(""));
	path = ft_strdup(env[i] + 5);
	return (path);
}

int	search(char **dec_path, char *commande, int i)
{
	char	*tmp;

	tmp = ft_strjoin(dec_path[i], commande);
	if (access(tmp, X_OK) != -1)
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

char	*get_path(char *av, char **env)
{
	char	**dec_path;
	char	*path;
	int		i;
	char	*commande;

	path = grep(env);
	commande = ft_strjoin("/", av);
	i = 0;
	dec_path = ft_split(path, ':');
	free(path);
	while (dec_path[i])
	{
		if (search(dec_path, commande, i))
			break ;
		i++;
	}
	if (!dec_path[i])
	{
		free_all(dec_path, commande);
		return (NULL);
	}
	path = ft_strjoin(dec_path[i], commande);
	free_all(dec_path, commande);
	return (path);
}
