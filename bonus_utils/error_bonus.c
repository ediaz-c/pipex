/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:32:14 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/28 17:33:10 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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
