/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:52:16 by fael-bou          #+#    #+#             */
/*   Updated: 2021/11/27 20:41:36 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	int		i;

	a = (char)c;
	i = 0;
	if (a == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == a)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
