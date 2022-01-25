CC = g++
CFLAGS = -Wall -Werror -Wextra -pedantic
OBJS = main.o sort.o

main: main.o sort.o
	$(CC) $(CFLAGS) -o program main.o sort.o

main.o: main.cpp sort.h
	$(CC) $(CFLAGS) -c main.cpp

sort.o: sort.h

clean:
	rm program $(OBJS)
