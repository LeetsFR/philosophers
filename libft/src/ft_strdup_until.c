/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:36:49 by mcollas           #+#    #+#             */
/*   Updated: 2024/03/24 13:27:05 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_until(const char *str, char separator)
{
	size_t	i;
	char	*strdup;

	if (str == NULL)
		return (NULL);
	strdup = malloc((ft_strlen_until(str, separator) + 1) * sizeof(char));
	if (strdup == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != separator)
	{
		strdup[i] = str[i];
		i++;
	}
	strdup[i] = '\0';
	return (strdup);
}
