/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ediaz--c <ediaz--c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:25:33 by ediaz--c          #+#    #+#             */
/*   Updated: 2023/04/17 19:05:22 by ediaz--c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_strlen(char *str);
int	ft_nbr_digits(int nb);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putptr_hex(unsigned long long nb);
int	ft_put_un_nbr(unsigned int nb);
int	ft_put_hex(unsigned int nb, char format);
int	ft_printf(const char *str, ...);

#endif
