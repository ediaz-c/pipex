/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:34:22 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/30 13:08:28 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	ft_create_heredoc(char	*limiter)
{
	int		fd[2];
	pid_t	pid;
	char	*line;

	open_pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (1)
		{
			write(0, "heredoc> ", 9);
			line = get_next_line(0);
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(0);
			write(fd[1], line, ft_strlen(line));
			free(line);
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
}

void	ft_check_files(t_pipex	*pipex, char **args, int n_args)
{
	if (ft_strncmp(args[1], "here_doc", ft_strlen("here_doc")) == 0
		&& n_args && pipex)
	{
		if (n_args < 6)
			ft_puterror("Numero de argumentos invalido con 'heredoc'\n");
		ft_create_heredoc(args[2]);
		pipex->fd_out = open(args[n_args - 1],
				O_CREAT | O_WRONLY | O_APPEND, 0000644);
		pipex->is_hd = 1;
	}
	else
	{
		pipex->fd_in = open(args[1], O_RDONLY);
		if (pipex->fd_in < 0)
			ft_error("Open infile", 1);
		pipex->fd_out = open(args[n_args - 1],
				O_TRUNC | O_CREAT | O_WRONLY, 0000644);
		pipex->is_hd = 0;
		dup2(pipex->fd_in, 0);
	}
	if (pipex->fd_out < 0)
		ft_error("Open outfile", 1);
}
