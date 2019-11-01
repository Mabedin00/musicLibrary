all: main.o functions.o
	gcc -o program main.o functions.o

main.o: main.c headers.h
	gcc -c -g main.c

functions.o: functions.c headers.h
	gcc -c -g functions.c

run:
	./program

clean:
	rm -rf program
	rm -rf *.o
