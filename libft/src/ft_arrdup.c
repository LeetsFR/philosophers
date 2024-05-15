/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 03:29:44 by mcollas           #+#    #+#             */
/*   Updated: 2024/03/31 17:49:40 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrdup(char **arr)
{
	size_t	i;
	char	**arrdup;

	arrdup = malloc((ft_arrlen(arr) + 1) * sizeof(char *));
	if (arrdup == NULL)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		arrdup[i] = ft_strdup(arr[i]);
		if (arrdup == NULL)
			return (ft_free_arr(arrdup), NULL);
		i++;
	}
	arrdup[i] = NULL;
	return (arrdup);
}
