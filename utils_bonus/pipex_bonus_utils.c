/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 00:20:31 by mhervoch          #+#    #+#             */
/*   Updated: 2024/03/31 23:05:27 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
