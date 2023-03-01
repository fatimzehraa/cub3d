/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:39:52 by fael-bou          #+#    #+#             */
/*   Updated: 2021/11/30 22:35:09 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*ascii_s;
	int		i;
	int		is_neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_neg = n < 0;
	i = count_size(n);
	ascii_s = malloc(i * sizeof(char) + 1);
	if (!ascii_s)
		return (NULL);
	ascii_s[0] = '-';
	ascii_s[i] = 0;
	if (is_neg)
		n = -n;
	while (i > is_neg)
	{
		i--;
		ascii_s[i] = n % 10 + '0';
		n = n / 10;
	}
	return (ascii_s);
}
