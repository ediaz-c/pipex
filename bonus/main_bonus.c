/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:31:06 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/30 14:05:42 by ediaz--c         ###   ########.fr       */
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
	while (i < pipex->n_cmds - 1)
	{
		ft_childs(pipex, args[index_cmd + i], env);
		i++;
	}
	dup2(pipex->fd_out, 1);
	ft_exec(*pipex, args[index_cmd + i], env);
	wait(NULL);
}

int	main(int ac, char *av[], char *ev[])
{
	t_pipex	pipex;

	if (ac < 5)
		ft_puterror("Numeros de argumentos invalidos\n");
	ft_check_files(&pipex, av, ac);
	ft_find_path(&pipex, ev);
	ft_process(&pipex, ac, av, ev);
}
