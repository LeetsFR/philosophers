/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:36:05 by mcollas           #+#    #+#             */
/*   Updated: 2024/04/08 21:21:29 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t size)
{
	size_t	i;
	char	*strdup;

	if (str == NULL)
		return (NULL);
	strdup = malloc((size + 1) * sizeof(char));
	if (strdup == NULL)
		return (NULL);
	i = 0;
	while (str[i] && i < size)
	{
		strdup[i] = str[i];
		i++;
	}
	strdup[i] = '\0';
	return (strdup);
}
