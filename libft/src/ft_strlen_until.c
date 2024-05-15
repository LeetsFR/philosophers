/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:40:23 by mcollas           #+#    #+#             */
/*   Updated: 2024/04/15 14:36:34 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_until(const char *str, char separator)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == separator)
			return (i);
		i++;
	}
	return (i);
}
