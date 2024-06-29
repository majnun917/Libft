/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:44:11 by ndieye            #+#    #+#             */
/*   Updated: 2022/11/12 00:45:46 by ndieye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digit(unsigned int n)
{
	unsigned int	i;

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

char	*ft_hex(int n, char *base)
{
	char					*nstr;
	size_t					len;
	unsigned int			num;

	len = ft_digit(n);
	nstr = malloc(len + 1);
	num = (unsigned int)n;
	if (!nstr)
		return (0);
	if (!num)
		nstr[0] = '0';
	nstr[len] = '\0';
	while (num > 0)
	{
		nstr[len - 1] = base[num % 16];
		num = num / 16;
		len--;
	}
	return (nstr);
}
