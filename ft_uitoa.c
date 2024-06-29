/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndieye <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 00:05:17 by ndieye            #+#    #+#             */
/*   Updated: 2022/10/28 21:33:00 by ndieye           ###   ########.fr       */
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
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char			*nstr;
	size_t			len;

	len = ft_digit(n);
	nstr = malloc(len + 1);
	if (!nstr)
		return (0);
	if (!n)
		nstr[0] = '0';
	nstr[len] = '\0';
	len--;
	while (n > 0)
	{
		nstr[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (nstr);
}
