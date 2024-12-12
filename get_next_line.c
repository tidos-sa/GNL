#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include "get_next_line_utils.h"

#define BUFFER_SIZE 1024


static char	*read_file(int fd, char *backup)
    {
        char	*buffer;
        int		read_bytes;
        buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buffer)
            return (NULL);
        read_bytes = 1;
        while (read_bytes > 0 && !ft_strchr(backup, '\n'))
        {
            read_bytes = read(fd, buffer, BUFFER_SIZE);
            if (read_bytes < 0)
                break ;
            buffer[read_bytes] = '\0';
            backup = ft_strjoin(backup, buffer);
        }
        free(buffer);
        if (read_bytes < 0)
            return (NULL);
        else
            return (backup);
    }

#include <stdio.h>

int main() {
    int fd;
    char *backup = NULL;

    // Abre o arquivo para leitura
    fd = open("oi.txt", O_RDONLY);
    if (fd < 0) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Chama a função read_file para ler o arquivo
    backup = read_file(fd, backup);
    if (backup == NULL) {
        perror("Erro ao ler o arquivo");
        close(fd);
        return 1;
    }

    // Exibe o conteúdo lido
    printf("Conteúdo lido do arquivo:\n%s\n", backup);

    // Fecha o arquivo e libera memória
    close(fd);
    free(backup);
    return 0;
}
