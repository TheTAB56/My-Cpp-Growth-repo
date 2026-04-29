#include <iostream>
using namespace std;

class Queue {
private:
    int max_size;
    int front = -1;
    int rear = -1;
    int* arr; 

public:
    // Constructor
    Queue(int user_size) {
        max_size = user_size;
        arr = new int[max_size]; 
        cout << "Queue of size " << max_size << " created successfully!\n" << endl;
    }

    // Destructor
    ~Queue() {
        delete[] arr; 
    }

    bool isEmpty() {
        return (front == -1 && rear == -1); 
    }

    bool isFull() {
        return (rear == max_size - 1);
    }

    void enqueue(int x) {
        if (!isFull()) {
            if (isEmpty()) {
                front = 0;
                rear = 0;
                arr[rear] = x;
            } else {
                arr[++rear] = x;
            }
            cout << "Enqueued: " << x << endl;
        } else {
            cout << "Queue Overflow! Cannot add " << x << endl;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            cout << "Dequeued: " << arr[front] << endl;
            if (front == rear) {
                // If there was only one element left, reset the queue
                front = -1;
                rear = -1;
                cout << "Queue is now entirely Empty." << endl;
            } else {
                // Otherwise, just move the front pointer forward
                front++;
            }
        } else {
            cout << "Queue Underflow! Nothing to dequeue." << endl;
        }
    }

    void showFront() {
        if (!isEmpty()) {
            cout << ">>> Front of the Queue is: " << arr[front] << " <<<" << endl; 
        } else {
            cout << "Queue is empty, no front element." << endl;
        }
    }

    void showFullQueue() {
        if (!isEmpty()) {
            cout << "\n--- Current Queue ---" << endl;
            for(int i = front; i <= rear; i++) {
                cout << arr[i] << endl; 
            }
            cout << "---------------------\n" << endl;
        } else {
            cout << "Cannot show queue because it is empty.\n" << endl;
        }
    }
};

int main() {
    int desired_size;

    // 1. Setup
    cout << "What should be the max size of your queue? ";
    cin >> desired_size;
    Queue test1(desired_size); 

    // 2. Testing Underflow (trying to dequeue an empty queue)
    cout << "--- Testing Underflow ---" << endl;
    test1.dequeue(); 
    test1.showFullQueue();



    // 3. Testing Enqueue and Overflow
    cout << "\n--- Testing Enqueue ---" << endl;
    for(int i = 1; i <= desired_size + 1; i++) {
        test1.enqueue(i * 10);
    }
    // Limitation of Linear Queue
    /*
    test1.dequeue();
    test1.dequeue();
    test1.dequeue();
    test1.enqueue(150); // output: Queue Overflow! Cannot add 150
    test1.enqueue(250); // output: Queue Overflow! Cannot add 250
    test1.enqueue(350); //  output: Queue Overflow! Cannot add 350, says overflow even when i have 3 spaces empty behind current front , but there is no way for front to access the indexes behind it, so false overflow
    */


    // 4. View the queue and the front element
    test1.showFullQueue();
    test1.showFront();

    // 5. Testing Dequeue
    cout << "\n--- Testing Dequeue ---" << endl;
    test1.dequeue(); // Removes the first item
    test1.dequeue(); // Removes the second item
    
    // 6. View the updated state
    test1.showFullQueue();
    test1.showFront();

    // 7. Emptying the rest of the queue to trigger the reset logic
    cout << "\n--- Emptying the Queue ---" << endl;
    // We loop until it's empty to trigger the front == rear reset block
    while(!test1.isEmpty()) {
        test1.dequeue();
    }

    return 0;
}