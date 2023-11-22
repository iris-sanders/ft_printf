/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irsander <irsander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:07:02 by irsander          #+#    #+#             */
/*   Updated: 2023/11/22 17:30:54 by irsander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	string_conversion(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	// if (c == 'p')
	// 	//void *pointer argument has to be printed in hexadecimal format
	// if (c == 'd')
	// 	//prints a decimal (base 10) number
	// if (c == 'i')
	// 	//prints an integer in base 10
	// if (c == 'u')
	// 	//unsigned decimal base 10 number
	// if (c == 'x')
	// 	//prints number in hexadecimal (base 16) lowercase
	// if (c == 'X')
	// 	//prints number in hexadecimal (base 16) uppercase
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int 	i;
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

/* Allowed functions:		Implement following conversions:
- malloc					
- free						
- write						- %p The void * pointer argument has to be printed in hexadecimal format
- va_start					- %d Prints a decimal (base 10) number
- va_arg					- %i Prints an integer in base 10
- va_copy					- %u Prints an unsigned decimal (base 10) number
- va_end					- %x Prints a number in hexadecimal (base 16) lowercase format
							- %X Prints a number in hexadecimal (base 16) uppercase format
							- %% Prints a percent sign
*/ 

int main(void)
{
	ft_printf("- print single character test\n");
	char character = 'a';
	ft_printf("  my printf: %c\n", character);
	printf("  og printf: %c\n\n", character);
	
	ft_printf("- print string test\n");
	char *string = "hallo";
	ft_printf("  my printf: %s\n", string);
	printf("  og printf: %s\n\n", string);

	ft_printf("- double percentage sign test\n");
	ft_printf("  my printf: %%\n");
	printf("  og printf: %%\n\n");
}