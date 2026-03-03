#include <iostream>
using namespace std;
#define STACK_SIZE 11

class Stack{  //LIFO = Last In First Out
    
    private:
        int top;
        int storage[STACK_SIZE];

    public:

        Stack(){  //constructor
            this->top = -1;
        }
        bool isEmpty(){
            if(top<0){
                cout<<"Stack Underflow!! Stack is Empty currently."<<endl;
                return true;
            }

            else{
                return false;
            }
        }

        void push(int top_number){
            if(top>= STACK_SIZE-1){
                cout<<"Stack Overflow!! Stack is Full currently."<<endl;
            }

            else{
                storage[++top] = top_number;
                cout<<"Succesfully pushed "<<top_number<<" and that is currently the top number in the stack."<<endl;
            }
        }

        void pop(){
            if(this->isEmpty()){}

            else{
                int temp_top = storage[top];
                top--;
                if(this->isEmpty()){}

                else{
                cout<<"The top number "<<temp_top<<" has been removed from the stack.\nCurrent top number in the stack is "<<storage[top]<<endl;
                }
            }
        }

        int getTop(){

            if(!(this->isEmpty())){
                return storage[top];
            }

            else{
                cout<<"If you see this then the Stack is empty. Returning -11111 as a marker for Stack Underflow";
                return -11111;
            }
        }


        void view_top(){
            if(this->isEmpty()){}

            else{
                cout<<"Currently the top number in the stack is: "<<this->getTop()<<endl;
            }
        }

        void show_full_stack(){

            if(this->isEmpty()){}

            else{
                for(int i=0; i<=top; i++){
                    cout<<"Position "<<i+1<<": "<<storage[i]<<endl;
                }
            }

        }
};

int main(){

    int arr[STACK_SIZE] ={ 5,8,7,9,2,4,3,12,2,1,0};

    Stack obs ; // OBS = Object Being Stack ,obs studio lol ,reference

    obs.show_full_stack();
    obs.pop();
    obs.view_top();
    for(int i=0; i<STACK_SIZE; i++){
        obs.push(arr[i]);
    }

    obs.show_full_stack();
    obs.view_top();
    obs.pop();
    obs.view_top();
    obs.show_full_stack();

    return 0;
}