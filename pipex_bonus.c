/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:23:31 by mhervoch          #+#    #+#             */
/*   Updated: 2024/04/01 22:32:07 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_process(char **commande, char **env, t_pipex *pipex, int i)
{
	dup2(pipex->fd_in, STDIN_FILENO);
	if (i == pipex->argc)
		dup2(pipex->fd_out, STDOUT_FILENO);
	else
		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	if (pipex->fd_in != -1)
	{
		if (pipex->fd_in > 2)
			close(pipex->fd_in);
		exec(commande, env, pipex);
	}
	ft_free_tab((void **) commande);
	free(pipex->path);
	exit(127);
}

void	global_fork(t_pipex *pipex, char **env, char **commande, int i)
{
	if (pipex->pid[i - 2] == 0)
	{
		if (!pipex->path)
		{
			printf("Command not found: %s\n", commande[0]);
			free_all(commande, pipex->path);
			exit(127);
		}
		fork_process(commande, env, pipex, i);
	}
	else
	{
		close(pipex->pipe_fd[1]);
		if (pipex->fd_in > 2)
			close(pipex->fd_in);
		pipex->fd_in = dup(pipex->pipe_fd[0]);
		close(pipex->pipe_fd[0]);
	}
}

int	child_process(char **env, char *av, t_pipex *pipex, int i)
{
	char	**commande;

	commande = ft_split(av, ' ');
	pipex->path = get_path(commande[0], env);
	if (pipe(pipex->pipe_fd) == -1)
	{
		free_all(commande, pipex->path);
		return (0);
	}
	pipex->pid[i - 2] = fork();
	if (pipex->pid[i - 2] == -1)
	{
		free_all(commande, pipex->path);
		return (0);
	}
	global_fork(pipex, env, commande, i);
	free_all(commande, pipex->path);
	return (1);
}

void	check_pid(char **env, char **av, t_pipex *pipex, int ac)
{
	int	i;

	i = 1;
	while (++i < ac - 1)
	{
		if (!child_process(env, av[i], pipex, i))
		{
			pipex->false_pid[i] = 0;
			return ;
		}
		else
			pipex->false_pid[i] = 1;
	}
	i = 1;
	while (++i < ac - 1)
	{
		if (pipex->false_pid[i])
			waitpid(pipex->pid[i - 2], NULL, 0);
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac <= 4)
	{
		printf("Error syntax\n");
		return (0);
	}
	pipex.argc = ac - 2;
	pipex.fd_in = open(av[1], O_RDONLY);
	if (pipex.fd_in == -1)
	{
		printf("%s: no such file or directory", av[1]);
		return (0);
	}
	pipex.fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	check_pid(env, av, &pipex, ac);
}
