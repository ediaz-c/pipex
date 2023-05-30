/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:55:45 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/30 16:49:58 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_find_path(t_pipex *pipex, char **ev)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (ft_strnstr(ev[i], "PATH=", 5) == 0)
		i++;
	if (!ev[i])
	{
		pipex->path_bin = NULL;
		return ;
	}
	tmp = ft_strchr(ev[i], '/');
	if (tmp == NULL)
		return ;
	pipex->path_bin = ft_split(pipex->path, ':');
	if (pipex->path_bin == NULL)
		return ;
    /*TODO*/
	return ;
}
