/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:59:58 by fael-bou          #+#    #+#             */
/*   Updated: 2021/11/26 13:37:33 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	s = malloc(size * count);
	if (s == NULL)
		return (NULL);
	while (i < size * count)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}
