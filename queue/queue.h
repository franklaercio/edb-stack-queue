#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

class Queue {
  private:
    int front;
    int back;
    int size;
    int *array;
    int capacity;
  public:
    Queue(int capacity);
    ~Queue();

    bool isFull();
    bool isEmpty();

    void enqueue(int item);
    void dequeue();
};

#endif