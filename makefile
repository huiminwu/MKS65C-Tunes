all: main.o song_node.o library.o
	gcc main.o song_node.o library.o

run: 
	./a.out

main.o: main.c song_node.c library.c
	gcc -c main.c song_node.c library.c

song_node.o: song_node.c song_node.h
	gcc -c song_node.c song_node.h

library.o: library.c library.h
	gcc -c library.c library.h
