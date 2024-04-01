/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 00:20:31 by mhervoch          #+#    #+#             */
/*   Updated: 2024/04/01 22:27:34 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *str)
{
	char	*cpy;
	char	*tmp;

	cpy = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	tmp = cpy;
	while (*str)
		*(tmp++) = *(str++);
	*tmp = 0;
	return (cpy);
}

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	free_all(char **cmd, char *path)
{
	free(path);
	ft_free_tab((void **) cmd);
}

int	exec(char **cmd, char **env, t_pipex *pipex)
{
	execve(pipex->path, cmd, env);
	free(pipex->path);
	return (1);
}
