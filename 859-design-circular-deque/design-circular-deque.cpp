class MyCircularDeque {
private:
    vector<int> buffer;
    int front;
    int rear;
    int count;
    int capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
        buffer.resize(k);
        front = 0;
        rear = 0;
        count = 0;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity; // wrap backward safely
        buffer[front] = value;
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        buffer[rear] = value;
        rear = (rear + 1) % capacity;
        count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        count--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return buffer[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        int lastIndex = (rear - 1 + capacity) % capacity;
        return buffer[lastIndex];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};