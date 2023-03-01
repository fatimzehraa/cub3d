/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:09:03 by fael-bou          #+#    #+#             */
/*   Updated: 2021/11/27 20:51:47 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stdlib.h>
#include<stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	length;
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	if (start >= length)
		return (ft_strdup(""));
	if ((length - start) < len)
		len = length - start;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	s += start;
	ft_strlcpy(str, s, len +1);
	return (str);
}
