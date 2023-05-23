/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:31:06 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/23 20:05:12 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int ac, char *av[], char *ev[])
{
	t_pipex	pipex;
	
	if (ac < 5)
		ft_puterror("Numeros de argumentos invalidos\n");
	if (ev)
		ft_check_files(&pipex, av, ac);
}