/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:23:31 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/12 20:49:50 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	father_process(char **env, char **av, int *pipe_fd)
{
	int		fd;
	char	**commande;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	commande = ft_split(av[3], ' ');
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	exec(commande, env);
	return (1);
}

int	child_process(char **env, char **av, int *pipe_fd)
{
	int		fd;
	char	**commande;

	fd = open(av[1], O_RDONLY, 0777);
	commande = ft_split(av[2], ' ');
	dup2(pipe_fd[1], STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	exec(commande, env);
	return (1);
}

int	main(int ac, char **av, char **env)
{
	int		pipe_fd[2];
	int		i;
	int		pid[2];
	int		iter;

	iter = (ac - 3) / 2;
	i = 0;
	if (ac < 4)
	{
		printf("pas bon\n");
		return (0);
	}
	while (i < iter)
	{
		if (pipe(pipe_fd) == -1)
			return (0);
		pid[i] = fork();
		if (pid[i] == 0)
		{
			if (i == 0)
				child_process(env, av, pipe_fd);
			else
				father_process(env, av, pipe_fd);
		}
		i++;
	}
	i = 0;
	while (i != 2)
		waitpid(pid[i++], NULL, 0);
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
		return (NULL);
	new_path = malloc(sizeof(char) * \
			ft_strlen(ft_strjoin(dec_path[i], commande)));
	new_path = ft_strjoin(dec_path[i], commande);
	return (new_path);
}
