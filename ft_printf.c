/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:11:01 by ndieye            #+#    #+#             */
/*   Updated: 2022/11/09 23:55:26 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		n;
	va_list	ap;

	i = 0;
	n = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			n += ft_arg(format, i, ap);
			i++;
		}
		else
			n += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (n);
}
