.DEFAULT_GOAL := all

queue.o: queue.cpp queue.h
	g++ queue.cpp -c

objects: queue.o

queue: objects main.cpp
	g++ -Wall -fsanitize=address queue.o main.cpp -o queue

clean:
	rm *.o *.csv queue

all: queue

run:
	./queue