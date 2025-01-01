/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mide-lim <mide-lim@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:36:45 by mide-lim          #+#    #+#             */
/*   Updated: 2024/12/21 14:34:20 by mide-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>

// --- Funções fornecidas --- //
size_t		ft_strlen(const char *s);
char		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);

// --- Funções do get_next_line --- //
char		*get_next_line(int fd);
//char		*extract_line(char *line);
//int			find_char(const char *s, char target);
//char		*read_line(int fd, char *buffer, char *storage);

#endif
