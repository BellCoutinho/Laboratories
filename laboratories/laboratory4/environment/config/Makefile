INCLUDE := \
		   -I ../../sources/includes\
		   -I ../../sources/includes/src

SRC 	:= ../../sources/src
BIN		:= ../bin
DOCS	:= ../../documentation/doxygen

CC := cc
CFLAGS := -Wall

all: compile docs run

run:
	@echo "===> Rodando"
	@./$(BIN)/lab4
	@echo "--- Rodando ok"

compile:
	@echo "===>	Compilando"
	@$(CC) $(CFLAGS) $(SRC)/*.c $(INCLUDE) -o $(BIN)/lab4
	@echo "--- Compilação ok"
docs:
	@echo "===> Gerando a documentação"
	@doxygen Doxyfile 1> /dev/null 2>&1
	@echo "--- Documentaçao ok"

clean:
	@echo "===> Removendo"
	@rm -rf $(BIN)/*
	@rm -rf $(DOCS)/*
	@echo "--- Removendo ok"
