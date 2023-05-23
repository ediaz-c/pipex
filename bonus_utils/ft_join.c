/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:52:46 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/23 19:54:18 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

char	*ft_join(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*join;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	join = malloc(sizeof(char) * len1 + len2 + 1);
	if (!join)
		return (NULL);
	ft_memmove(join, s1, len1);
	ft_memmove(join + len1, s2, len2);
	join[len1 + len2] = '\0';
	free((char *)s1);
	return (join);
}