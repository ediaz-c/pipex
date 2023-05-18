/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:22:04 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/18 15:03:42 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*reg;
	size_t			i;

	reg = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		reg[i] = '\0';
		i++;
	}
}
