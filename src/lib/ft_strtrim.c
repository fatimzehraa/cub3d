/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:39:22 by fael-bou          #+#    #+#             */
/*   Updated: 2021/11/26 22:00:04 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*copy;
	int		i;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	start = 0;
	end = ft_strlen(s1) -1;
	i = 0;
	while (s1[start] && ft_strchr(set, s1[start]) != NULL)
		start++;
	while (end > start && ft_strchr(set, s1[end]) != NULL)
		end--;
	copy = ft_calloc((end - start + 2), sizeof(char));
	if (copy == NULL)
		return (0);
	while (start + i < end + 1)
	{
		copy[i] = s1[start + i];
		i++;
	}
	return (copy);
}
