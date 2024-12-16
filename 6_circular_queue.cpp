#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE], front = -1, rear = -1;

public:
    void enqueue(int value) {
        if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) {
            cout << "Queue Full!\n";
            return;
        }
        rear = (rear + 1) % SIZE;
        if (front == -1) front = 0;
        arr[rear] = value;
    }

    int dequeue() {
        if (front == -1) {
            cout << "Queue Empty!\n";
            return -1;
        }
        int data = arr[front];
        if (front == rear) front = rear = -1;
        else front = (front + 1) % SIZE;
        return data;
    }

    void display() {
        if (front == -1) {
            cout << "Queue Empty!\n";
            return;
        }
        for (int i = front; i != rear; i = (i + 1) % SIZE)
            cout << arr[i] << " ";
        cout << arr[rear] << endl;
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();
    cout << "Dequeued: " << cq.dequeue() << endl;
    cq.display();
    return 0;
}

