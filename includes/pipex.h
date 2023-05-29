/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:36:41 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/29 18:53:14 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# define READ 0
# define WRITE 1

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		fd_in;
	int		fd_out;
	char	*path;
	char	**path_bin;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;

// void	ft_childs(t_pipex *pipex, char **args, char **env);
/*
* Encuentra el "PATH" en las variables de entorno
* y crea una matriz con cada ruta.
*/
void	ft_find_path(t_pipex *pipex, char **ev);
void	ft_free_path(char **args);
char	*ft_join(char *s1, char *s2);
void	ft_error(char *err, int nexit);
void	ft_puterror(char *err, int nexit);
void	ft_first_child(t_pipex pipex, char **args, char **env);
void	ft_second_child(t_pipex pipex, char **args, char **env);
void	ft_process(t_pipex *pipex, char **args, char **env);
void	ft_close_pipes(t_pipex *pipex);
#endif