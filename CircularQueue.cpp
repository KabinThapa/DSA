#include<iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, size;
    int* CQ;

public:
    CircularQueue(int size) {
        this->size = size;
        front = -1;
        rear = -1;
        CQ = new int[size];
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "The queue is overflowed!\n";
        } else {
            if (front == -1) front = 0;  
            rear = (rear + 1) % size;
            CQ[rear] = item;
            cout << item << " has been enqueued to the queue\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow!\n";
        } else {
            cout << CQ[front] << " has been dequeued!\n";
            if (front == rear) { 
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % size;
            }
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "The queue is empty!\n";
        } else {
            cout << "The elements in the queue are: ";
            int i;
            for (i = front; i != rear; i = (i + 1) % size) {
                cout << CQ[i] << " ";
            }
            cout << CQ[i] << endl; 
        }
    }

    void summation() { 
        if (isEmpty()) {
            cout << "Queue is empty, sum is 0\n";
            return;
        }
        int sum = 0;
        int i;
        for (i = front; i != rear; i = (i + 1) % size) { 
            sum += CQ[i];
        }
        sum += CQ[i]; 
        cout << "The sum of all elements is: " << sum << endl;
    }
};

int main() {
    int s, choice, val;
    cout << "Enter the size of the Circular Queue: ";
    cin >> s;
    CircularQueue q(s);

    while (true) {
        cout << "\n--- Menu ---\n1. Enqueue\n2. Dequeue\n3. Display\n4. Summation\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                q.summation();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}