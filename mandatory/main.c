/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:34:32 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/30 20:06:54 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_close_pipes(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

int	main(int ac, char *av[], char *ev[])
{
	t_pipex	pipex;

	if (ac != 5)
		ft_puterror("Numero de argumentos invalidos\n", 1);
	pipex.fd_in = open(av[1], O_RDONLY);
	if (pipex.fd_in < 0)
		perror("infile");
	pipex.fd_out = open(av[ac - 1], O_TRUNC | O_CREAT | O_WRONLY, 0000644);
	if (pipex.fd_out < 0)
		ft_error("Outfile", 22);
	if (pipe(pipex.fd) < 0)
		ft_error("Pipe", 0);
	ft_find_path(&pipex, ev);
	ft_process(&pipex, av, ev);
	return (0);
}
