/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:58:15 by fael-bou          #+#    #+#             */
/*   Updated: 2021/11/27 18:17:53 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;
	size_t		j;

	d = (char *)dst;
	s = (const char *)src;
	i = 0;
	j = len;
	if (!dst && !src)
		return (dst);
	if (src > dst)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (j--)
			d[j] = s[j];
	}
	return (dst);
}
