/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:32:43 by fael-bou          #+#    #+#             */
/*   Updated: 2021/11/21 17:52:42 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*arr1;
	const char	*arr2;

	i = 0;
	arr1 = (const char *)s1;
	arr2 = (const char *)s2;
	while (i < n)
	{
		if (arr1[i] != arr2[i])
			return ((unsigned char)arr1[i] - (unsigned char)arr2[i]);
		i++;
	}
	return (0);
}
