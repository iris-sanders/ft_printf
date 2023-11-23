/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irsander <irsander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:07:02 by irsander          #+#    #+#             */
/*   Updated: 2023/11/23 01:38:59 by irsander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string_conversion(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int), 10, 0, 0));
	else if (c == 'u')
		return (ft_putnbr(va_arg(args, int), 10, 1, 0));
	else if (c == 'x')
		return (ft_putnbr(va_arg(args, int), 16, 1, 1));
	else if (c == 'X')
		return (ft_putnbr(va_arg(args, int), 16, 1, 2));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
		// return (ft_putnbr(va_arg(args, int), 16, 2, 1));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			length += string_conversion(args, s[i]);
		}
		else
			length += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (length);
}

// int main(void)
// {
// 	ft_printf("- c: print single character test\n");
// 	char character = 'a';
// 	ft_printf("  my printf: %c\n", character);
// 	printf("  og printf: %c\n\n", character);

// 	ft_printf("- s: print string test\n");
// 	char *string = "hallo";
// 	ft_printf("  my printf: %s\n", string);
// 	printf("  og printf: %s\n\n", string);

// 	ft_printf("- %: double percentage sign test\n");
// 	ft_printf("  my printf: %%\n");
// 	printf("  og printf: %%\n\n");

// 	ft_printf("- i: print integer in base 10 test\n");
// 	int	num = 543;
// 	ft_printf("  my printf: %i\n", num);
// 	printf("  og printf: %i\n\n", num);

// }