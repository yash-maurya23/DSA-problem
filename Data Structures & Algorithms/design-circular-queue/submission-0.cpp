#include <vector>

using namespace std;

class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;
    int capacity;

public:
    // Initializes the object with the size of the queue to be k
    MyCircularQueue(int k) {
        data.resize(k);
        head = 0;
        tail = -1;
        size = 0;
        capacity = k;
    }
    
    // Inserts an element into the circular queue. Return true if the operation is successful.
    bool enQueue(int value) {
        if (isFull()) return false;
        
        // Move tail forward circularly and insert
        tail = (tail + 1) % capacity;
        data[tail] = value;
        size++;
        return true;
    }
    
    // Deletes an element from the circular queue. Return true if the operation is successful.
    bool deQueue() {
        if (isEmpty()) return false;
        
        // Move head forward circularly
        head = (head + 1) % capacity;
        size--;
        return true;
    }
    
    
    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }
    
  
    int Rear() {
        if (isEmpty()) return -1;
        return data[tail];
    }

    bool isEmpty() {
        return size == 0;
    }
    
    // Checks whether the circular queue is full or not.
    bool isFull() {
        return size == capacity;
    }
};
