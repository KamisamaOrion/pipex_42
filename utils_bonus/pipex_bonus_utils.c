/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 00:20:31 by mhervoch          #+#    #+#             */
/*   Updated: 2024/03/12 23:13:19 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_all(char **cmd, char *path)
{
	free(path);
	ft_free_tab((void **) cmd);
}

int	exec(char **cmd, char **env)
{
	char	*path;

	path = get_path(cmd[0], env);
	if (!path)
		path = ft_strdup("");
	execve(path, cmd, env);
	return (1);
}
