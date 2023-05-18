/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:08:24 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/18 15:03:47 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <limits.h>

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*reg;

	if (size > 0 && nitems > ULONG_MAX / size)
		return (0);
	reg = malloc (nitems * size);
	if (!(reg == NULL))
		ft_bzero(reg, size * nitems);
	return (reg);
}
