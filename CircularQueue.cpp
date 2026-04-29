#include <iostream>
using namespace std;

class Queue {
    private:
        int front =-1;
        int rear =-1;
        int max_size;
        int* arr;

    public:
        Queue(int x){
            max_size =x;
            arr = new int[max_size];
        }

        ~Queue(){
            delete[] arr;
        }

        bool isEmpty(){
            if(front == -1 && rear == -1)return true;
            else return false;
        }

        bool isFull(){
            if((rear+1)%max_size == front)return true;
            else return false;
        }

        void enqueue(int x){
            if(isFull()){
                cout<<"Queue Overflow!"<<endl;
            }
            else{
                if(isEmpty()){
                    front = 0;
                    rear = 0;
                    arr[rear] = x;
                    cout<<"Enqueued at index "<<rear<<": "<<x<<endl;
                }

                else{
                    rear = (rear+1)%max_size;
                    arr[rear] = x;
                    cout<<"Enqueued at index "<<rear<<": "<<x<<endl;
                }
            }
        }

        void dequeue(){
            if(isEmpty())cout<<"Queue Underflow!"<<endl;
            else {
                if(front == rear){
                    cout<<"Dequeued element: "<<arr[front]<<endl;
                    front = -1;
                    rear = -1;
                }
                else{ 
                    cout<<"Dequeued element that was at index "<<front<<": "<<arr[front]<<endl;
                    front = (front+1)%max_size;
                }
            }
        }

        void showFront(){
            if(isEmpty()){
                cout<<"Queue is Empty at the moment."<<endl;
            }
            else{
                cout<<"Front of the Queue is: "<<arr[front]<<endl;
            }
        }

        void showFullQueue(){
            if(isEmpty()){
                cout<<"Queue is fully Empty at the moment."<<endl;
            }

            else{
                int i = front;
                do{
                    cout<<"Element at Index pos "<<i<<" : "<<arr[i]<<endl;
                    i = (i+1)%max_size;
                }
                while(i!=(rear+1)%max_size);
                    
                
            }
        }
};



int main() {
    // Set a small size to easily trigger overflows and wrap-arounds
    int size = 4;
    cout << "=== INITIALIZING CIRCULAR QUEUE (SIZE " << size << ") ===" << endl;
    Queue q(size);

    cout << "\n--- TEST 1: Underflow (Empty Queue) ---" << endl;
    // Trying to break it before adding anything
    q.dequeue(); 
    q.showFront();
    q.showFullQueue();

    cout << "\n--- TEST 2: Normal Enqueue ---" << endl;
    // Partially filling the queue
    q.enqueue(10); // Index 0
    q.enqueue(20); // Index 1
    q.enqueue(30); // Index 2
    q.showFront(); // Should be 10
    q.showFullQueue();

    cout << "\n--- TEST 3: Overflow (Filling it to max) ---" << endl;
    q.enqueue(40); // Index 3. Queue is now completely full (4 out of 4).
    q.enqueue(50); // Should trigger "Queue Overflow!"
    q.showFullQueue();

    cout << "\n--- TEST 4: Dequeue (Opening space at the front) ---" << endl;
    q.dequeue(); // Removes 10 from index 0
    q.dequeue(); // Removes 20 from index 1
    // The queue now has empty space at the beginning, but the rear is at the end.
    q.showFront(); // Should be 30
    
    cout << "\n--- TEST 5: Circular Wrap-Around ---" << endl;
    // This proves the modulo math works. These should drop into index 0 and 1.
    q.enqueue(50); // Wraps to Index 0
    q.enqueue(60); // Wraps to Index 1
    
    // Attempting to add one more should overflow again
    q.enqueue(70); // Should trigger "Queue Overflow!"
    
    // This proves your do-while loop works flawlessly! 
    // It should print starting from index 2, then 3, then wrap to 0, then 1.
    q.showFullQueue(); 

    cout << "\n--- TEST 6: Complete Drain (Resetting to -1) ---" << endl;
    q.dequeue(); // Removes 30 (from index 2)
    q.dequeue(); // Removes 40 (from index 3)
    q.dequeue(); // Removes 50 (from index 0)
    q.dequeue(); // Removes 60 (from index 1) -> Triggers the front == rear reset!
    
    // Checking if the reset actually worked
    q.dequeue(); // Should trigger "Queue Underflow!"
    q.showFullQueue();

    cout << "\n--- TEST 7: Post-Reset Enqueue ---" << endl;
    // Checking if it behaves like a brand new queue after being drained
    q.enqueue(100); 
    q.showFront();
    q.showFullQueue();

    return 0;
}