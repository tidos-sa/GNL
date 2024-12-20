anotacao breve sobre, fre no ft_strjoin para evitar leek
    ----

    static char	*read_file(int fd, char *backup)
    {
        -criar um ponteiro char buffer*;
        criar uma variavel int para ler a quantidade de bytes na linha

        
        mallocar o tamanho certo do buffer, a variavel que vc criou a cima  malloc(sizeof(char) * (BUFFER_SIZE + 1)); // lembrando o BUFFER_SIZE é definido no terminal 


        if (!buffer)
            return (NULL);

        verificar se o buffer recebeu o tamanho para receber a string

        read_bytes = 1;
        definir o tamanho da variavel read_bytes pra 1, para fazer um looping.

        lopping de verificacao 
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

    -------

    funcao responsavel por ler linha por linha.

   static char	*get_line(char	*backup)
{
    char	*line;
    size_t	size;

    criar duas variaveis um ponteiro pra linha
    e um size_t para o tamanho da respectiva linha

    if (!*backup)
        return (NULL);

        verificar se o backup existea algo armazenado

    size = 0;

    definir tamanho do size_t que criou la encima

    while (backup[size] && backup[size] != '\n')
        size++;

    um loop para calcular o tamanho de caracteres ate a ocorrencia \n

    line = (char *)malloc(sizeof(char) * (size + 2));

    malocar o tamanho especifico para a linha considerando o \n e \0 ou seja ao inves de +1 sera +2 por conta dos dois parametros 

    if (!line)
        return (NULL);

    verificar se foi malocado corretamente

    ft_strlcpy(line, backup, size + 1);
    copiar a linha 
    if (backup[size] == '\n')
        line[size++] = '\n';
    line[size] = '\0';
    return (line);
}


