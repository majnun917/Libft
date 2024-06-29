/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:27:55 by ndieye            #+#    #+#             */
/*   Updated: 2022/11/17 14:11:10 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digit(unsigned long n)
{
	unsigned long	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char	*ft_ptr(unsigned long n, char *base)
{
	char					*nstr;
	size_t					len;

	len = ft_digit(n);
	nstr = malloc(len + 1);
	if (!nstr)
		return (0);
	if (!n)
		nstr[0] = '0';
	nstr[len] = '\0';
	while (n > 0)
	{
		nstr[len - 1] = base[n % 16];
		n = n / 16;
		len--;
	}
	return (nstr);
}
