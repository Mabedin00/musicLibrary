ifeq($(DEBUG),true)
	$(CC): gcc -c -g
else
	$(CC): gcc -c
endif

all: main.o linked_list.o music_library.o
	gcc -o program main.o linked_list.o music_library.o

main.o: main.c linked_list.h music_library.h
	$(CC) main.c

linked_list.o: linked_list.c linked_list.h
	$(CC) linked_list.c

music_library.o: music_library.c music_library.h
	$(CC) music_library.c

run:
	./program

clean:
	rm -rf program
	rm -rf *.o
