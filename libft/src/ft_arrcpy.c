/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:01:43 by mcollas           #+#    #+#             */
/*   Updated: 2024/03/31 13:05:36 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrcpy(char **dest, char **src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = ft_strdup(src[i]);
		if (dest[i] == NULL)
			return (NULL);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
