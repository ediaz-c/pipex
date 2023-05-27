/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:31:06 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/27 17:20:48 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	ft_process(t_pipex *pipex, int n_args, char **args, char **env)
{
	int	i;
	int	index_cmd;

	i = 0;
	pipex->n_cmds = n_args - 3 - pipex->is_hd;
	index_cmd = 2 + pipex->is_hd;
	pipex->n_args = n_args;
	close(pipex->fd_pipe[FDR][WRITE]);
	while (i < pipex->n_cmds - 1)
	{
		ft_childs(pipex, args[index_cmd + i], env);
		i++;
	}
	dup2(pipex->fd_out, 1);
	ft_exec(*pipex, args[index_cmd + i], env);
	ft_wait(pipex->n_cmds);
}

int	main(int ac, char *av[], char *ev[])
{
	t_pipex	pipex;

	if (ac < 5)
		ft_puterror("Numeros de argumentos invalidos\n");
	ft_check_files(&pipex, av, ac);
	if (ft_find_path(&pipex, ev) == 0)
		ft_puterror("Error en el 'PATH'\n");
	if (pipe(pipex.fd_pipe[FDR]) < 0)
		ft_error("pipe");
	if (pipe(pipex.fd_pipe[FDW]) == -1)
		ft_error("pipe");
	ft_process(&pipex, ac, av, ev);
}
