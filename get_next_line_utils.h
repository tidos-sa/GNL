#ifndef GET_NEXT_LINE_UTILS_H
# define GET_NEXT_LINE_UTILS_H
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <string.h>

size_t	ft_strlen(const char	*s);
char	*ft_strchr(const char	*s, int	c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char	*s1, char const	*s2);
size_t	ft_strlcpy(char	*dest, const char	*src, size_t	size);

#endif