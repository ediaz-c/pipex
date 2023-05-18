/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_un_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:05:44 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/04/17 19:07:17 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_nbr(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	ft_print_nb(unsigned int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_print_nb(-nb);
	}
	else if (nb > 9)
	{
		ft_print_nb(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	else
		ft_putchar((nb % 10) + '0');
}

int	ft_put_un_nbr(unsigned int nb)
{
	ft_print_nb(nb);
	return (ft_len_nbr(nb));
}
