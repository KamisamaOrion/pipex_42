/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:23:52 by mhervoch          #+#    #+#             */
/*   Updated: 2024/03/31 23:05:42 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		pipe_fd[2];
	pid_t	pid[1024];
	int		fd_in;
	int		fd_out;
	int		argc;
	char	*path;

}	t_pipex;

char	*get_path(char *cmd, char **env);
char	*grep(char **env);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_strlen(char const*s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		exec(char **cmd, char **env, t_pipex *pipex);
int		ft_printf(const char *f, ...);
void	ft_free_tab(void **tab);
char	*ft_strdup(char *str);

#endif
