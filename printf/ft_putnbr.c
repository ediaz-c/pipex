/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:25:54 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/04/13 21:25:56 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_nbr(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
	{
		nb = -nb;
		len++;
	}
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	ft_print_nbr(int nb)
{
	if (nb == INT_MIN)
	{
		ft_putstr("-2");
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	else
		ft_putchar((nb % 10) + '0');
}

int	ft_putnbr(int nb)
{
	ft_print_nbr(nb);
	return (ft_len_nbr(nb));
}
