CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS= 
EXEC = main
all : $(EXEC)

main : graphe.o main.o liste.o dijkstra.o
	gcc -o $@ $^ $(LDFLAGS)
%.o : %.c
	gcc -o $@ -c $< $(CFLAGS)
clean:
	rm -rf *.o

mrproper: clean
	rm -rf &(EXEC)

