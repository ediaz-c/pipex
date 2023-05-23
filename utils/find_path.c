/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:55:45 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/23 19:20:20 by ediaz--c         ###   ########.fr       */
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
	if (ev[i] == NULL)
		ft_puterror("Variables de entorno");
	tmp = ft_strchr(ev[i], '/');
	if (tmp == NULL)
		ft_puterror("Variables de entorno");
	pipex->path = tmp;
	pipex->path_bin = ft_split(pipex->path, ':');
	if (pipex->path_bin == NULL)
		ft_puterror("Variables de entorno");
}
