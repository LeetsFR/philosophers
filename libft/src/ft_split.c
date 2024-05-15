/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:59:57 by mcollas           #+#    #+#             */
/*   Updated: 2024/03/24 14:40:51 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(const char *str, char separator)
{
	size_t	i;
	size_t	words;
	char	**split;

	if (str == NULL)
		return (NULL);
	words = ft_count_words(str, separator);
	split = malloc((words + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*str && *str == separator)
			str++;
		split[i] = ft_strndup(str, ft_strlen_until(str, separator));
		if (split[i] == NULL)
			return (ft_free_arr(split), NULL);
		str += ft_strlen_until(str, separator);
		i++;
	}
	split[i] = NULL;
	return (split);
}
