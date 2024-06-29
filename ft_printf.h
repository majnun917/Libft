/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:16:05 by ndieye            #+#    #+#             */
/*   Updated: 2022/11/17 11:03:05 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_arg(const char *frmt, int i, va_list ap);
int		ft_putstr(char *str);
int		ft_putchar(char c);

char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_hex(int n, char *base);
char	*ft_ptr(unsigned long n, char *base);
#endif
