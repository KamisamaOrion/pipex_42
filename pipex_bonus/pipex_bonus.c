/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:23:31 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/26 23:18:22 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	child_process(char **env, char *av, t_pipex *pipex, int i)
{
	char	**commande;

	commande = ft_split(av, ' ');
	if (pipe(pipex->pipe_fd) == -1)
		return (1);
	pipex->pid[i - 2] = fork();
	if (pipex->pid[i - 2] == -1)
		return (1);
	if (pipex->pid[i - 2] == 0)
	{
		dup2(pipex->fd_in, STDIN_FILENO);
		if (i == pipex->argc)
			dup2(pipex->fd_out, STDOUT_FILENO);
		else
			dup2(pipex->pipe_fd[1], STDOUT_FILENO);
		close(pipex->pipe_fd[0]);
		close(pipex->pipe_fd[1]);
		close(pipex->fd_in);
		if (pipex->fd_in != -1)
			exec(commande, env);
	}
	else
	{
		close(pipex->pipe_fd[1]);
		close(pipex->fd_in);
		pipex->fd_in = dup(pipex->pipe_fd[0]);
		close(pipex->pipe_fd[0]);
	}
	return (1);
}

int	main(int ac, char **av, char **env)
{
	int	i;
	t_pipex pipex;

	i = 0;
	if (ac < 4)
	{
		printf("pas bon\n");
		return (0);
	}
	pipex.argc = ac - 2;
	pipex.fd_in = open(av[1] , O_RDONLY, 0777);
	pipex.fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	i = 2;
	pipex.pid = malloc(sizeof(pid_t) * ac - 2 - i + 1);
	while (i < ac - 1)
	{
		child_process(env, av[i], &pipex, i);
		i++;
	}
	i = 2;
	while (i < ac - 1)
	{
		waitpid(pipex.pid[i - 2], NULL, 0);
		i++;
	}
}

char	*grep(char **env)
{
	char	*path;
	int		i;

	i = 0;
	while (strncmp(env[i], "PATH=", 5))
		i++;
	path = malloc(sizeof(char) * ft_strlen(env[i]) - 5);
	path = env[i] + 5;
	printf("%s", path);
	return (path);
}

char	*get_path(char *av, char **env)
{
	char	**dec_path;
	char	*path;
	char	*new_path;
	int		i;
	char	*commande;

	path = grep(env);
	dec_path = ft_split(av, ' ');
	commande = ft_strjoin("/", dec_path[0]);
	i = 0;
	dec_path = ft_split(path, ':');
	while (dec_path[i] && access(ft_strjoin(dec_path[i], commande), X_OK) == -1)
		i++;
	if (!dec_path[i])
	{
		ft_printf("Command not found: %s\n", av);
		return (NULL);
	}
	new_path = malloc(sizeof(char) * \
			ft_strlen(ft_strjoin(dec_path[i], commande)));
	new_path = ft_strjoin(dec_path[i], commande);
	return (new_path);
}
