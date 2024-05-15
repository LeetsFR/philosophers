/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:50:25 by mcollas           #+#    #+#             */
/*   Updated: 2024/04/09 12:56:21 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, char chr)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == chr)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
