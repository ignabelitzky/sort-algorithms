CC = g++
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c++20
OBJS = main.o

main: main.o
	$(CC) $(CFLAGS) -o program main.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm program $(OBJS)
