/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:38:50 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/23 19:21:04 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_puterror(char *err)
{
	write(2, err, ft_strlen(err));
	exit(0);
}

void	ft_error(char *err)
{
	perror(err);
	exit(0);
}
