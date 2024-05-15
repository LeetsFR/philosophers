/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:45:17 by mcollas           #+#    #+#             */
/*   Updated: 2024/04/15 21:48:41 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *first, const char *second)
{
	size_t	i;
	size_t	j;
	char	*strjoin;

	if (first == NULL || second == NULL)
		return (NULL);
	strjoin = malloc((ft_strlen(first) + ft_strlen(second) + 1) * sizeof(char));
	if (strjoin == NULL)
		return (NULL);
	i = 0;
	while (first[i])
	{
		strjoin[i] = first[i];
		i++;
	}
	j = 0;
	while (second[j])
	{
		strjoin[i] = second[j];
		i++;
		j++;
	}
	strjoin[i] = '\0';
	return (strjoin);
}
