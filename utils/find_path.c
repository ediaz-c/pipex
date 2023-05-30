/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:55:45 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/30 17:13:04 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_find_path(t_pipex *pipex, char **ev)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ev[i] && ft_strnstr(ev[i], "PATH=", 5) == 0)
		i++;
	if (!ev[i])
	{
		pipex->path_bin = NULL;
		return ;
	}
	pipex->path_bin = ft_split(ev[i] + 5, ':');
	if (pipex->path_bin == NULL)
		return ;
	return ;
}
