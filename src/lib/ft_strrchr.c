/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:47:36 by fael-bou          #+#    #+#             */
/*   Updated: 2021/11/27 20:42:54 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	int		i;

	a = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == a)
			return ((char *) s + i);
		i--;
	}
	return (0);
}
