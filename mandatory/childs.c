/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:27:38 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/30 16:46:48 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*ft_get_bin(char **paths, char *cmd)
{
	int		i;
	char	*tmp;
	char	*command;

	i = 0;
	if (access(cmd, F_OK) == 0)
		return (cmd);
	if (paths == NULL)
		return (NULL);
	while (paths[i])
	{
		tmp = ft_join(paths[i], "/");
		command = ft_join(tmp, cmd);
		free(tmp);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

void	ft_second_child(t_pipex pipex, char **args, char **env)
{
	dup2(pipex.fd[READ], 0);
	close(pipex.fd[WRITE]);
	dup2(pipex.fd_out, 1);
	pipex.cmd_args = ft_split(args[3], ' ');
	if (pipex.cmd_args == NULL)
	{
		ft_free_path(pipex.cmd_args);
		ft_error("Malloc", 0);
	}
	pipex.cmd = ft_get_bin(pipex.path_bin, pipex.cmd_args[0]);
	if (execve(pipex.cmd, pipex.cmd_args, env) == -1)
	{
		ft_free_path(pipex.cmd_args);
		ft_error("EXEC", 127);
	}
}

void	ft_first_child(t_pipex pipex, char **args, char **env)
{
	// dup2(pipex.fd[WRITE], 1);
	close(pipex.fd[WRITE]);
	dup2(pipex.fd_in, 0);
	if (pipex.fd_in < 0)
		exit (0);
	pipex.cmd_args = ft_split(args[2], ' ');
	if (pipex.cmd_args == NULL)
	{
		ft_free_path(pipex.cmd_args);
		ft_error("Malloc", 0);
	}
	pipex.cmd = ft_get_bin(pipex.path_bin, pipex.cmd_args[0]);
	if (execve(pipex.cmd, pipex.cmd_args, env) == -1)
	{
		ft_free_path(pipex.cmd_args);
		ft_error("EXEC", 127);
	}
}

void	ft_process(t_pipex *pipex, char **args, char **env)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
		ft_first_child(*pipex, args, env);
	if (pipex->pid1 < 0)
		ft_error("PID", 0);
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
		ft_second_child(*pipex, args, env);
	if (pipex->pid2 < 0)
		ft_error("PID", 0);
	ft_close_pipes(pipex);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	ft_free_path(pipex->path_bin);
}
