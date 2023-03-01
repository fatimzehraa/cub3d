/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:09:11 by fael-bou          #+#    #+#             */
/*   Updated: 2021/12/01 02:42:17 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		a;
	const char	*str;

	str = (const char *)s;
	a = (char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == a)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
