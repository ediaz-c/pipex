/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:57:54 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/30 20:15:55 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_exec(t_pipex pipex, char *args, char **env)
{
	pipex.cmd_args = ft_split(args, ' ');
	if (pipex.cmd_args == NULL)
	{
		ft_free_path(pipex.cmd_args);
		ft_puterror("args");
	}
	pipex.cmd = ft_get_bin(pipex.path_bin, pipex.cmd_args[0]);
	if (execve(pipex.cmd, pipex.cmd_args, env) == -1)
	{
		if (ft_strncmp(pipex.cmd, pipex.cmd_args[0], ft_strlen(pipex.cmd)) != 0)
			ft_free_path(pipex.cmd_args);
		free(pipex.cmd);
		ft_error("exec", 127);
	}
	free(pipex.cmd);
	ft_free_path(pipex.cmd_args);
	exit(0);
}

void	ft_childs(t_pipex *pipex, char *args, char **env)
{
	int	child_pipe[2];

	if (pipe(child_pipe) == -1)
		ft_error("pipe", 0);
	pipex->pid = fork();
	if (pipex->pid == 0)
	{
		close(child_pipe[READ]);
		dup2(child_pipe[WRITE], 1);
		ft_exec(*pipex, args, env);
	}
	else
	{
		close(child_pipe[WRITE]);
		dup2(child_pipe[READ], 0);
		waitpid(pipex->pid, NULL, 0);
	}
}
