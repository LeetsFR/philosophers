/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:46:25 by mcollas           #+#    #+#             */
/*   Updated: 2024/04/10 18:08:20 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *first, const char *second)
{
	size_t	i;

	if (first == NULL || second == NULL)
		return (-1);
	i = 0;
	while (first[i] && second[i] && first[i] == second[i])
		i++;
	return (first[i] - second[i]);
}
