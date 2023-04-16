# Makefile commentsÖÖ
PROGRAMS = driver
CC = gcc
CFLAGS = -Wall -g
all: $(PROGRAMS)
clean:
	rm -f *.o
# C compilations
data.o: data.c data.h
	$(CC) $(CFLAGS) -c data.c
tree.o: tree.c tree.h data.h
	$(CC) $(CFLAGS) -c tree.c
priorityQueue.o: priorityQueue.c priorityQueue.h tree.h data.h
	$(CC) $(CFLAGS) -c priorityQueue.c
driver.o: driver.c tree.h data.h
	$(CC) $(CFLAGS) -c driver.c
# Executable programs
driver: driver.o tree.o data.o priorityQueue.o
	$(CC) $(CFLAGS) -o driver driver.o priorityQueue.o tree.o data.o

