/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidos-sa <tidos-sa@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:19:10 by tidos-sa          #+#    #+#             */
/*   Updated: 2025/01/03 21:28:31 by tidos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *line)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	len = (ft_strlen(line) - i);
	tmp = ft_substr(line, i + 1, len);
	if (*tmp == '\0')
	{
		free(tmp);
		tmp = NULL;
	}
	line[i + 1] = '\0';
	return (tmp);
}

static int	find_char(const char *s, char target)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == target)
			return (1);
		i++;
	}
	return (0);
}

char	*read_line(int fd, char *buffer, char *storage)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		if (!storage)
			storage = ft_strdup("");
		tmp = storage;
		storage = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (find_char(buffer, '\n'))
			break ;
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, storage);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	storage = extract_line(line);
	return (line);
}
/*
// --- Main para testes --- //
#include <fcntl.h> // Para open()
#include <stdio.h> // Para printf()

int	main(void)
{
	int		fd;
	char	*line;

	// Abra o arquivo de teste
	fd = open("test_file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erro ao abrir o arquivo");
		return (1);
	}

	// Teste a função get_next_line
	printf("=== Testando get_next_line ===\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Linha lida: %s", line);
		free(line);
	}

	// Feche o arquivo
	close(fd);
	return (0);
}*/
