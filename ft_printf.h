/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irsander <irsander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:07:06 by irsander          #+#    #+#             */
/*   Updated: 2023/11/22 17:23:50 by irsander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

//ft_printf.c
int    ft_printf(const char *, ...);

//ft_printf_utils.c
int		ft_putchar(char c);
int		ft_putstr(char *s);

#endif