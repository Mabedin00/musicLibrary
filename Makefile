all: main.o linked_list.o music_library.o
	gcc -o program main.o linked_list.o music_library.o

main.o: main.c linked_list.h music_library.h
	gcc -c -g main.c

linked_list.o: linked_list.c linked_list.h
	gcc -c -g linked_list.c

music_library.o: music_library.c music_library.h
	gcc -c -g music_library.c

run:
	./program

clean:
	rm -rf program
	rm -rf *.o
