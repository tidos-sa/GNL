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