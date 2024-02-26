/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 00:20:31 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/26 20:01:32 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	exec(char **cmd, char **env)
{
	char	*path;

	path = get_path(cmd[0], env);
	//if (path == NULL)
	//	return (0);
	if (execve(path, cmd, env) == -1)
	{
		printf("command not found");
		return (0);
	}
	return (1);
}
