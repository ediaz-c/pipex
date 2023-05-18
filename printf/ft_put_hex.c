/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:50:26 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/04/17 19:03:59 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_hex(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

static void	ft_print_hex(unsigned int nb, int isUpper)
{
	if (nb >= 16)
	{
		ft_print_hex((nb / 16), isUpper);
		ft_print_hex(nb % 16, isUpper);
	}
	else if (nb > 9)
	{
		if (isUpper)
			ft_putchar(nb - 10 + 'A');
		else
			ft_putchar(nb - 10 + 'a');
	}
	else
		ft_putchar(nb + '0');
}

int	ft_put_hex(unsigned int nb, char format)
{
	if (nb == 0)
		return (ft_putchar('0'));
	else
		ft_print_hex(nb, format == 'X');
	return (ft_len_hex(nb));
}
