#include <bits/stdc++.h>
using namespace std;

struct Queue {
    int front, rear, capacity;
    int* queue;
    
    // Constructor to initialize the queue
    Queue(int c)
    {
        front = 0;
        rear = -1;
        capacity = c;
        queue = new int[c];
    }

    // Destructor to free the allocated memory
    ~Queue() { delete[] queue; }

    // Function to insert an element at the rear of the queue
    void queueEnqueue(int data)
    {
        // Check if the queue is full
        if (rear == capacity - 1) {
            printf("\nQueue is full\n");
            return;
        }

        // Insert element at the rear
        queue[++rear] = data;
    }

    // Function to delete an element from the front 
    // of the queue
    void queueDequeue()
    {
        // If the queue is empty
        if (front > rear) {
            printf("\nQueue is empty\n");
            return;
        }

        // Shift all elements from index 1 till rear to 
        // the left by one
        for (int i = 0; i < rear; i++) {
            queue[i] = queue[i + 1];
        }

        // Decrement rear
        rear--;
    }

    // Function to print queue elements
    void queueDisplay()
    {
        if (front > rear) {
            printf("\nQueue is Empty\n");
            return;
        }

        // Traverse front to rear and print elements
        for (int i = front; i <= rear; i++) {
            printf(" %d <-- ", queue[i]);
        }
        printf("\n");
    }

    // Function to print the front of the queue
    void queueFront()
    {
        if (rear == -1) {
            printf("\nQueue is Empty\n");
            return;
        }
        printf("\nFront Element is: %d\n", queue[front]);
    }
};

// Driver code
int main(void)
{
    // Create a queue of capacity 4
    Queue q(4);

    // Print queue elements
    q.queueDisplay();

    // Insert elements in the queue
    q.queueEnqueue(20);
    q.queueEnqueue(30);
    q.queueEnqueue(40);
    q.queueEnqueue(50);

    // Print queue elements
    q.queueDisplay();

    // Insert element in the queue
    q.queueEnqueue(60);

    // Print queue elements
    q.queueDisplay();

    // Dequeue elements
    q.queueDequeue();
    q.queueDequeue();

    printf("\nAfter two node deletions\n");

    // Print queue elements
    q.queueDisplay();
    
    printf("\nAfter one insertion\n");
    q.queueEnqueue(60);
    
    // Print queue elements
    q.queueDisplay();

    // Print front of the queue
    q.queueFront();

    return 0;
}
