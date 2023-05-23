/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:34:22 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/23 20:16:18 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	ft_create_heredoc(char	*limiter)
{
	char	*heredoc;
	char	*line;
	char	*input;
	
	heredoc = "heredoc> ";
	input = NULL;
	while (1)
	{
		write(0, heredoc, ft_strlen(heredoc));
		line = get_next_line(0);
		if (line == NULL || ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			printf("%s\n", input);
			break ;
		}
		input = ft_join(input, line);
		free(line);
	}
}

void	ft_check_files(t_pipex	*pipex, char **args, int n_args)
{
	if (ft_strncmp(args[1], "here_doc", ft_strlen("here_doc")) == 0 && n_args && pipex)
		ft_create_heredoc(args[2]);
}