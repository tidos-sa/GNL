/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mide-lim <mide-lim@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:00:00 by mide-lim          #+#    #+#             */
/*   Updated: 2025/01/01 15:30:00 by mide-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>  // Para usar open()
#include <stdio.h>  // Para usar printf()

// Função para testar extract_line
void	test_extract_line(void)
{
	char	*line = ft_strdup("Teste de linhaa\naaaaaaaRestante da string");
	char	*rest;

	printf("Antes do extract_line:\n");
	printf("Line: %s\n", line);

	rest = extract_line(line);

	printf("\nDepois do extract_line:\n");
	printf("Line: %s\n", line);
	printf("Restante: %s\n", rest);

	free(line);
	free(rest);
}

// Função para testar find_char
void	test_find_char(void)
{
	char	*test_string = "Essa é uma string de teste\nCom nova linha";
	char	target = '\n';

	printf("\nTestando find_char:\n");
	printf("String: %s\n", test_string);
	printf("Caractere procurado: '%c'\n", target);
	printf("Resultado: %s\n", find_char(test_string, target) ? "Encontrado" : "Não encontrado");
}

// Função para testar read_line
void	test_read_line(void)
{
	int		fd;
	char	*buffer;
	char	*storage = NULL;

	fd = open("test_file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erro ao abrir o arquivo");
		return ;
	}

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return ;

	printf("\nTestando read_line:\n");
	storage = read_line(fd, buffer, storage);
	printf("Resultado do read_line: %s\n", storage);

	free(buffer);
	free(storage);
	close(fd);
}

// Função para testar get_next_line
void	test_get_next_line(void)
{
	int		fd;
	char	*line;

	fd = open("test_file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erro ao abrir o arquivo");
		return ;
	}

	printf("\nTestando get_next_line:\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Linha: %s", line);
		free(line);
	}

	close(fd);
}

int	main(void)
{
	printf("=== Testando extract_line ===\n");
	test_extract_line();

	printf("\n=== Testando find_char ===\n");
	test_find_char();

	printf("\n=== Testando read_line ===\n");
	test_read_line();

	printf("\n=== Testando get_next_line ===\n");
	test_get_next_line();

	return (0);
}
