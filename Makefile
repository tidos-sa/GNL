# Defina o compilador
CC = gcc

# Defina as flags de compilação
CFLAGS = -Wall -Wextra -Werror

# Defina os arquivos fontes
SRCS = get_next_line.c  get_next_line_utils.c

# Defina os arquivos objetos (arquivos .o gerados pela compilação)
OBJS = $(SRCS:.c=.o)

# Nome do executável
NAME = get_next_line

# Regra principal para compilar o projeto
all: $(NAME)

# Regra para gerar o executável
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Regra para compilar arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar arquivos temporários
clean:
	rm -f $(OBJS)

# Regra para limpar o executável
fclean: clean
	rm -f $(NAME)

# Regra para recompilar tudo
re: fclean all
