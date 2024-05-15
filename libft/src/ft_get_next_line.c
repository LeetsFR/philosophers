/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:51:16 by mcollas           #+#    #+#             */
/*   Updated: 2024/04/11 21:29:25 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy_rest(char *str, char *source)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (source[i] != '\n')
		i++;
	i++;
	while (source[i])
		str[j++] = source[i++];
	str[j] = '\0';
}

char	*ft_strjoin_gn(char *start, char *end)
{
	int		i;
	int		j;
	char	*str;

	str = malloc((ft_strlen(start) + ft_strlen(end) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (start[i])
		str[j++] = start[i++];
	i = 0;
	while (end[i])
		str[j++] = end[i++];
	str[j] = '\0';
	free(start);
	return (str);
}

char	*ft_strdup_line(char *source)
{
	int		i;
	char	*str;

	i = 0;
	while (source[i] != '\n')
		i++;
	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (source[i] != '\n')
	{
		str[i] = source[i];
		i++;
	}
	str[i] = '\n';
	i++;
	str[i] = '\0';
	free(source);
	return (str);
}

char	*get_next_line(int fd)
{
	int			i_read;
	static char	str_read[BUFFER_SIZE + 1];
	char		*line;

	i_read = BUFFER_SIZE;
	line = ft_strdup(str_read);
	while (!ft_strchr(str_read, '\n') && i_read == BUFFER_SIZE)
	{
		i_read = read(fd, str_read, BUFFER_SIZE);
		str_read[i_read] = '\0';
		if (i_read < BUFFER_SIZE)
		{
			if (!str_read[0] && !line[0])
				return (free(line), NULL);
		}
		line = ft_strjoin_gn(line, str_read);
	}
	if (!ft_strchr(line, '\n'))
	{
		str_read[0] = '\0';
		return (line);
	}
	return (ft_strcpy_rest(str_read, line), ft_strdup_line(line));
}
