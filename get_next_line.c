/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mide-lim <mide-lim@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:37:12 by mide-lim          #+#    #+#             */
/*   Updated: 2024/12/22 16:31:00 by mide-lim         ###   ########.fr       */
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
	len = ft_strlen(line) - i;
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
            return (1); // Retorna 1 se o caractere for encontrado.
        i++;
    }
    return (0); // Retorna 0 se o caractere não for encontrado.
}

char	*read_line(int fd, char *buffer, char *storage)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)//fim do arquivo
			break ;
		if (bytes_read < 0)//erro na leitura
			return (NULL);
		buffer[bytes_read] = '\0';
		if (!storage)//inicializa com uma string vazia
			storage = ft_strdup("");
		tmp = storage;
		storage = ft_strjoin(tmp, buffer);//atualiza storage
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
		return (NULL);//Verifica se o descritor de arquivo é válido
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, storage);//concatena com no storage
	free(buffer);
	buffer = NULL;
	if (!line)//Se nenhuma linha foi lida
		return (NULL);
	storage = extract_line(line);//prepara o storage ate o '\n'
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
}
*/