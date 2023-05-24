/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:57:54 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/24 18:02:42 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_first_child(t_pipex pipex, char *args, char **env)
{
	dup2(pipex.fd_in, 0);
	close(pipex.fd_in);
	dup2(pipex.fd_pipe[FDW][WRITE], 1);
	close(pipex.fd_pipe[FDW][WRITE]);
	if (pipex.fd_in >= 0)
	{
		pipex.cmd_args = ft_split(args, ' ');
		if (pipex.cmd_args != NULL)
		{
			pipex.cmd = ft_get_bin(pipex.path_bin, pipex.cmd_args[0]);
			if (pipex.cmd != NULL)
			{
				if (execve(pipex.cmd, pipex.cmd_args, env))
					exit (1) ;
			}
		}
	}
	ft_free_path(pipex.cmd_args);
	close(pipex.fd_pipe[FDW][READ]);
	close(pipex.fd_pipe[FDR][READ]);
	close(pipex.fd_pipe[FDR][WRITE]);
	exit(0);
}

void	ft_last_child(t_pipex pipex, char *args, char **env)
{
	dup2(pipex.fd_pipe[FDW][READ], 0);
	close(pipex.fd_pipe[FDW][READ]);
	dup2(pipex.fd_out, 1);
	pipex.cmd_args = ft_split(args, ' ');
	if (pipex.cmd_args != NULL)
	{
		pipex.cmd = ft_get_bin(pipex.path_bin, pipex.cmd_args[0]);
		if (pipex.cmd != NULL)
		{
			if (execve(pipex.cmd, pipex.cmd_args, env))
				exit (1);
		}
	}
	ft_free_path(pipex.cmd_args);
	close(pipex.fd_pipe[FDW][WRITE]);
	close(pipex.fd_pipe[FDR][READ]);
	close(pipex.fd_pipe[FDR][WRITE]);
	exit(0);
}

void	ft_middle_childs(t_pipex pipex, char *args, char **env)
{
	dup2(pipex.fd_pipe[FDW][READ], 0);
	close(pipex.fd_pipe[FDW][READ]);
	dup2(pipex.fd_pipe[FDW][WRITE], 1);
	pipex.cmd_args = ft_split(args, ' ');
	if (pipex.cmd_args != NULL)
	{
		pipex.cmd = ft_get_bin(pipex.path_bin, pipex.cmd_args[0]);
		if (pipex.cmd != NULL)
		{
			if (execve(pipex.cmd, pipex.cmd_args, env))
				exit (1);
		}
	}
	ft_free_path(pipex.cmd_args);
	close(pipex.fd_pipe[FDW][WRITE]);
	close(pipex.fd_pipe[FDR][READ]);
	close(pipex.fd_pipe[FDR][WRITE]);
	exit(0);
}

void	ft_childs(t_pipex *pipex, char *args, char **env, int index)
{
	printf("%s\n", args);
	pipex->pid = fork();
	if (pipex->pid == 0)
	{
		if ((2 + pipex->is_hd) == index)
			ft_first_child(*pipex, args, env);
		else if (index == pipex->n_args - 2)
			ft_last_child(*pipex, args, env);
		else
			ft_middle_childs(*pipex, args, env);
	}
	else if (pipex->pid < 0)
		ft_error("FORK");
}