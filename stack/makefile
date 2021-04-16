.DEFAULT_GOAL := all

stack.o: stack.cpp stack.h
	g++ stack.cpp -c

objects: stack.o

stack: objects main.cpp
	g++ -Wall -fsanitize=address stack.o main.cpp -o stack

clean:
	rm *.o stack

all: stack

run:
	./stack