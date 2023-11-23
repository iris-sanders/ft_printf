/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irsander <irsander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:06:58 by irsander          #+#    #+#             */
/*   Updated: 2023/11/23 01:04:57 by irsander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long num, int base, int u_nbr, int upcase)
{
	int	length;

	length = 0;
	if (u_nbr == 1)
		num = (unsigned int)num;
	if (base == 10 && num < 0)
	{
		length += ft_putchar('-');
		num = -num;
	}
	if (num >= base)
		length += ft_putnbr(num / base, base, u_nbr, upcase);
	num = num % base;
	if (num < 10)
		length += ft_putchar(num + '0');
	else
	{
		if (upcase == 1)
			length += ft_putchar(num + ('a' - 10));
		else if (upcase == 2)
			length += ft_putchar(num + ('A' - 10));
	}
	return (length);
}
