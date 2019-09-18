
CC := cc

all: fibonacci.o 

fibonacci.o: teste_fibonacci.c
	$(CC) $^ -o $@ 

run:
	./fibonacci.o
clean:
	rm -rf *.o
