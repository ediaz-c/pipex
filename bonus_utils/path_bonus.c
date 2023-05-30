/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:53:20 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/30 20:13:01 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

char	*ft_get_bin(char **paths, char *cmd)
{
	int		i;
	char	*tmp;
	char	*command;

	i = 0;
	if (cmd == NULL)
		return (NULL);
	if (!ft_strncmp(cmd, "/", 1) || !ft_strncmp(cmd, "./", 2)
		|| !ft_strncmp(cmd, "../", 3))
		return (cmd);
	if (paths == NULL)
		return (NULL);
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

void	ft_find_path(t_pipex *pipex, char **env)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (env[i] && ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	if (!env[i])
	{
		pipex->path_bin = NULL;
		return ;
	}
	tmp = ft_strchr(env[i], '/');
	if (tmp == NULL)
		return ;
	pipex->path_bin = ft_split(tmp, ':');
	if (pipex->path_bin == NULL)
		return ;
	return ;
}
