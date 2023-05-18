/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:07:49 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/04/17 19:08:39 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_ptr(unsigned long long nb)
{
	int	len;

	len = 0;
	while (nb)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

static void	ft_print_ptr(unsigned long long nb)
{
	if (nb >= 16)
	{
		ft_print_ptr(nb / 16);
		ft_print_ptr(nb % 16);
	}
	else if (nb > 9)
		ft_putchar(nb - 10 + 'a');
	else
		ft_putchar(nb + '0');
}

int	ft_putptr_hex(unsigned long long nb)
{
	ft_putstr("0x");
	if (nb == 0)
		return (ft_putchar('0') + 2);
	else
		ft_print_ptr(nb);
	return (ft_len_ptr(nb) + 2);
}
