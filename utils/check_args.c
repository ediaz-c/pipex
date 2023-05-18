/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:58:45 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/18 15:18:08 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_check_infile(char *path)
{
	int	file;
	if (access(path, F_OK) == -1 || access(path, R_OK) == -1)
		ft_puterror(stderr(errno));
		
}

void	ft_check_args(int n_args, char **args)
{
	int	i;

	i = 1;
	while (i < n_args)
	{
		if (i == 1)
			ft_check_infile(args[i]);
		else
			ft_check_cmd(args[i]);
		i++;
	}
}