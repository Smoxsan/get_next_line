/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:56:44 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/25 12:58:08 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int search_str);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
void	*ft_calloc(size_t num_elements, size_t element_size);
char	*get_next_line(int fd);
#endif