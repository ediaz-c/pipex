/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:53:58 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/05/18 15:05:01 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	if (str1 == str2 || n == 0)
		return (str1);
	if (str1 > str2)
	{
		while (n-- > 0)
		{
			s1[n] = s2[n];
		}
	}
	else
	{
		while (i < n)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	return (str1);
}
