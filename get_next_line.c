#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#include "get_next_line_utils.h"

#define BUFFER_SIZE 1024


static char	*read_file(int fd, char *backup)
    {
        char *buffer;
        int len_bytes;

        buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));

        if (!buffer)
        {
            return NULL;
        }

        len_bytes = 1;

        while (len_bytes > 0 && !ft_strchr(backup, '\n'))
        {
            len_bytes = read(fd, buffer, BUFFER_SIZE);
            if (len_bytes < 0)
            {
                break ;
            }
            buffer[len_bytes] = '\0';
            backup = ft_strjoin(backup,buffer);
        }

        free(buffer);
        if (len_bytes < 0)
            return (NULL);
        else
            return (backup);
}


static char	*new_line(char	*backup)
{
    char	*line;
    size_t	size;

    if (!*backup)
        return (NULL);
    size = 0;
    while (backup[size] && backup[size] != '\n')
        size++;
    
    line = (char *)malloc(sizeof(char) * (size + 2));
    
    if (!line)
        return (NULL);

    ft_strlcpy(line, backup, size + 1);

    if (backup[size] == '\n')
        line[size++] = '\n';
        
    line[size] = '\0';
    return (line);
}


static char	*remove_read_line(char *backup)
{
    int		i;
    int		j;
    char	*new_backup;

    i = 0;
    while (backup[i] && backup[i] != '\n')
        i++;
    if (!backup[i])
    {
        free(backup);
        return (NULL);
    }
    new_backup = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
    if (!new_backup)
        return (NULL);
    i++;
    j = 0;
    while (backup[i])
        new_backup[j++] = backup[i++];
    new_backup[j] = '\0';
    free(backup);
    return (new_backup);
}


int main(void) {
    int fd;
    char *line;

    // Abrindo o arquivo para leitura.
    fd = open("oi.txt", O_RDONLY);
    if (fd < 0) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Lendo o arquivo linha por linha e imprimindo cada linha.
    while ((line = get_next_line(fd)) != NULL) {
        printf("Linha lida: %s", line);  // Imprime a linha lida
        free(line);  // Libera a memória alocada pela função get_next_line
    }

    // Fechando o arquivo depois que ele foi lido.
    close(fd);

    return 0;
}