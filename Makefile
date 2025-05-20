CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lm

# Encontra todos os arquivos .c recursivamente
SRCS = $(shell find . -name "*.c")
# Gera uma lista de executáveis (mesmo nome do .c, sem extensão)
TARGETS = $(SRCS:.c=)

.PHONY: all clean distclean

all: $(TARGETS)

# Regra para ligar cada executável e remover seu .o após a compilação
%: %.o
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)
	@rm -f $<  # Remove o .o silenciosamente

# Regra para compilar .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa TODOS os arquivos temporários (incluindo os do crun)
clean:
	@echo "Limpando arquivos temporários..."
	@find . \( -name "*.o" -o -name "*.out" -o -name "a.out" -o -name "*.exe" \) -type f -delete
	@find . -type f -executable -not -path "./.git/*" -exec rm -f {} \;

# Limpa tudo, incluindo os executáveis
distclean: clean
	@echo "Removendo executáveis..."
	@find . -type f -executable -not -path "./.git/*" -exec rm -f {} \;