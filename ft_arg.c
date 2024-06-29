/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:14:52 by ndieye            #+#    #+#             */
/*   Updated: 2022/11/17 11:01:54 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbri(int a)
{
	char	*str;
	int		n;

	str = ft_itoa(a);
	n = ft_putstr(str);
	free(str);
	return (n);
}

int	ft_putnbru(unsigned int a)
{
	char			*str;
	unsigned int	n;

	str = ft_uitoa(a);
	n = ft_putstr(str);
	free(str);
	return (n);
}

int	ft_puthex(unsigned int a, char *base)
{
	char			*str;
	unsigned int	nb;

	str = ft_hex(a, base);
	nb = ft_putstr(str);
	free(str);
	return (nb);
}

int	ft_putptr(void *a, char *base)
{
	char				*str;
	unsigned int		nb;
	unsigned long		n;

	n = (unsigned long)a;
	str = ft_ptr(n, base);
	nb = ft_putstr(str);
	free(str);
	return (nb);
}

int	ft_arg(const char *frmt, int i, va_list ap)
{
	if (frmt[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (frmt[i + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (frmt[i + 1] == 'p')
		return (ft_putstr("0x") + ft_putptr(va_arg(ap, void *),
				"0123456789abcdef"));
	else if (frmt[i + 1] == 'i' || frmt[i + 1] == 'd')
		return (ft_putnbri(va_arg(ap, int)));
	else if (frmt[i + 1] == 'u')
		return (ft_putnbru(va_arg(ap, unsigned int)));
	else if (frmt[i + 1] == 'x')
		return (ft_puthex((va_arg(ap, unsigned int)), "0123456789abcdef"));
	else if (frmt[i + 1] == 'X')
		return (ft_puthex((va_arg(ap, unsigned int)), "0123456789ABCDEF"));
	else if (frmt[i + 1] == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(frmt[i + 1]));
}
