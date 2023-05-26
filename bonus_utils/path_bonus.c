/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:53:20 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/26 12:28:24 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

char	*ft_get_bin(char **paths, char *cmd)
{
	int		i;
	char	*tmp;
	char	*command;

	i = 0;
	if (access(cmd, F_OK) == 0)
		return (cmd);
	while (paths[i])
	{
		tmp = ft_join(paths[i], "/");
		command = ft_join(tmp, cmd);
		free(tmp);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

int	ft_find_path(t_pipex *pipex, char **env)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while ((ft_strnstr(env[i], "PATH=", 5) == 0))
		i++;
	if (env[i] == NULL)
		return (0);
	tmp = ft_strchr(env[i], '/');
	if (tmp == NULL)
		return (0);
	pipex->path_bin = ft_split(tmp, ':');
	if (pipex->path_bin == NULL)
		return (0);
	return (1);
}