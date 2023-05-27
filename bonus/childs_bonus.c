/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:57:54 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/27 17:20:58 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

// static void	ft_first_child(t_pipex pipex, int fd_read, int fd_write)
// {
// 	close(fd_read);
// 	dup2(fd_write, 1);
// 	close(fd_write);
// 	close(pipex.fd_out);
// }

// static void	ft_last_child(t_pipex pipex, int fd_read, int fd_write)
// {
// 	dup2(fd_read, 0);
// 	close(fd_read);
// 	dup2(pipex.fd_out, 1);
// 	close(fd_write);
// }

// static void	ft_middle_childs(t_pipex pipex, int fd_read, int fd_write)
// {
// 	dup2(fd_read, 0);
// 	close(fd_read);
// 	dup2(fd_write, 1);
// 	close(fd_write);
// 	close(pipex.fd_in);
// 	close(pipex.fd_out);
// }

void	ft_exec(t_pipex pipex, char *args, char **env)
{
	pipex.cmd_args = ft_split(args, ' ');
	if (pipex.cmd_args == NULL)
	{
		ft_free_path(pipex.cmd_args);
		exit(1);
	}
	pipex.cmd = ft_get_bin(pipex.path_bin, pipex.cmd_args[0]);
	if (pipex.cmd == NULL)
	{
		free(pipex.cmd);
		ft_free_path(pipex.cmd_args);
		exit(1);
	}
	if (execve(pipex.cmd, pipex.cmd_args, env) == -1)
	{
		free(pipex.cmd);
		ft_free_path(pipex.cmd_args);
		exit(1);
	}
	free(pipex.cmd);
	ft_free_path(pipex.cmd_args);
	exit(0);
}

void	ft_childs(t_pipex *pipex, char *args, char **env)
{
	if (pipe(pipex->fd_pipe[FDW]))
		ft_error("pipe");
	// close(pipex->fd_pipe[FDW][READ]);
	pipex->pid = fork();
	if (pipex->pid == 0)
	{
		close(pipex->fd_pipe[FDW][READ]);
		dup2(pipex->fd_pipe[FDW][WRITE], 1);
		ft_exec(*pipex, args, env);
	}
	else
	{
		close(pipex->fd_pipe[FDW][WRITE]);
		dup2(pipex->fd_pipe[FDW][READ], 0);
		waitpid(pipex->pid, NULL, 0);
	}
	// dup2(pipex->fd_pipe[FDW][READ],pipex->fd_pipe[FDR][READ]);
}
