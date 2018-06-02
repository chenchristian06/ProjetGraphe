CFLAGS=-c -g
LDFLAGS=

all: main

main: graphe.o hachage.o dijkstra.o tas.o test.o
	gcc  -o $@ $^ $(LDFLAGS)

%.o: %.c
	gcc $(CFLAGS) $<

clean :
	rm *.o $^
