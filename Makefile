CFLAGS=-c -g 
LDFLAGS=

all: main

main: graphe.o liste.o dijkstra.o main.o
	gcc  -o $@ $^ $(LDFLAGS)

%.o: %.c
	gcc $(CFLAGS) $< 

clean :
	rm *.o $^
