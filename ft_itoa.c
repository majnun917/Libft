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

static int	ft_digit(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*nstr;
	size_t			len;
	long			num;

	len = ft_digit(n);
	nstr = malloc(len + 1);
	num = (long)n;
	if (!nstr)
		return (0);
	if (!num)
		nstr[0] = '0';
	if (num < 0)
	{
		nstr[0] = '-';
		num = num * -1;
	}
	nstr[len] = '\0';
	len--;
	while (num > 0)
	{
		nstr[len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (nstr);
}
