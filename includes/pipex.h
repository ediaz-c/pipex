/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:50:53 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/18 14:53:28 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../gnl/get_next_line.h"

//	src

//	utils
void	ft_check_args(int n_args, char **args);
void	ft_puterror(char *str);
#endif