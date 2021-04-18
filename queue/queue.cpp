#include "queue.h"

#include <iostream>

Queue::Queue(int capacity) {
  this->capacity = capacity;
  this->front = size = 0;
  this->back = capacity - 1;
  this->array = new int[capacity];
}

Queue::~Queue() {
  delete[] array;
}

bool Queue::isFull() {
  return this->size == this->capacity;
}

bool Queue::isEmpty() {
  return this->size == 0;
}

void Queue::enqueue(int item) {
  if (isFull()) {
    return;
  }

  this->back = (back + 1) % capacity;
  this->array[back] = item; 
  this->size = size + 1;
}

void Queue::dequeue() {
  if(isEmpty()) {
    return;
  }

  this->front = (front + 1) % capacity;
  this->size -= 1;
}