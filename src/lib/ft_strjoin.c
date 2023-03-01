/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:43:18 by fael-bou          #+#    #+#             */
/*   Updated: 2021/11/26 16:46:58 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdlib.h>
#include<stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		s1_len;
	int		s2_len;

	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	ft_strlcpy(s, s1, s1_len + 1);
	ft_strlcat(s, s2, s1_len + s2_len + 1);
	return (s);
}
