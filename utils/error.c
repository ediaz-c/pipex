/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:38:50 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/29 18:53:03 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_puterror(char *err, int nexit)
{
	write(2, err, ft_strlen(err));
	exit(nexit);
}

void	ft_error(char *err, int nexit)
{
	perror(err);
	exit(nexit);
}
