/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:17:22 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/23 19:53:39 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	pid_t	*pid;
	int		fd_move[2];
	int		fd_rw[2];
	int		fd_in;
	int		fd_out;
	char	**path_bin;
	char	**cmd_args;
	char	*cmd;
}	t_pipex;

void	ft_puterror(char *err);
void	ft_check_files(t_pipex	*pipex, char **args, int n_args);
char	*ft_join(char const *s1, char const *s2);
#endif