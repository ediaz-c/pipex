/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:57:54 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/26 15:55:46 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_first_child(t_pipex pipex)
{
	dup2(pipex.fd_in, 0);
	close(pipex.fd_in);
	dup2(pipex.fd_pipe[FDW][WRITE], 1);
	close(pipex.fd_pipe[FDW][WRITE]);
	close(pipex.fd_pipe[FDW][READ]);
}

void	ft_last_child(t_pipex pipex)
{
	dup2(pipex.fd_pipe[FDR][READ], 0);
	close(pipex.fd_pipe[FDR][READ]);
	dup2(pipex.fd_out, 1);
	close(pipex.fd_pipe[FDW][WRITE]);
	close(pipex.fd_pipe[FDW][READ]);
}

void	ft_middle_childs(t_pipex pipex)
{
	dup2(pipex.fd_pipe[FDR][READ], 0);
	close(pipex.fd_pipe[FDR][READ]);
	dup2(pipex.fd_pipe[FDW][WRITE], 1);
	close(pipex.fd_pipe[FDW][WRITE]);
	close(pipex.fd_pipe[FDW][READ]);
}

void	ft_childs(t_pipex *pipex, char *args, char **env, int index)
{
	pipex->pid = fork();
	if (pipex->pid == 0)
	{
		if ((2 + pipex->is_hd) == index)
			ft_first_child(*pipex);
		else if (index == pipex->n_args - 2)
			ft_last_child(*pipex);
		else 
			ft_middle_childs(*pipex);
		pipex->cmd_args = ft_split(args, ' ');
		if (pipex->cmd_args != NULL)
		{
			pipex->cmd = ft_get_bin(pipex->path_bin, pipex->cmd_args[0]);
			if (pipex->cmd_args != NULL)
			{
				if (execve(pipex->cmd, pipex->cmd_args, env) == -1)
				{
					free(pipex->cmd_args);
					ft_free_path(pipex->cmd_args);
					exit(1);
				}
				free(pipex->cmd_args);
			}
			ft_free_path(pipex->cmd_args);
		}
	}
}
