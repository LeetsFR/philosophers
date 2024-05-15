/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:17:09 by mcollas           #+#    #+#             */
/*   Updated: 2024/05/14 17:28:18 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 600

size_t			ft_strlen(const char *str);
size_t			ft_strlen_until(const char *str, char separator);
size_t			ft_arrlen(char **arr);
size_t			ft_count_words(const char *str, char separator);
char			*ft_strdup(const char *str);
char			*ft_strndup(const char *str, size_t size);
char			*ft_strchr(const char *str, char chr);
char			*ft_strjoin(const char *first, const char *second);
char			*get_next_line(int fd);
char			**ft_arrdup(char **arr);
char			**ft_arrcpy(char **dest, char **src);
char			**ft_split(const char *str, char separator);
int				ft_strcmp(const char *first, const char *second);
int				ft_strncmp(const char *first, const char *second,
					size_t length);
int				ft_atoi(const char *str);
long			ft_atol(const char *str);
unsigned long	ft_atoul(const char *str);
bool			ft_isalpha(char c);
bool			ft_isalnum(char c);
void			ft_print_arr(char **arr);
void			ft_error(const char *str);
void			ft_free_arr(char **arr);

#endif
