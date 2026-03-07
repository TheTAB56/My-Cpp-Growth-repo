#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;


class BasicCalculator {

    private:
        static const int stack_size = 100;
        int top;
        char stack[stack_size];

    public:
        BasicCalculator(){
            this->top = -1;
        }
    
        string postFix_output = "";

        bool isEmpty(){
            if(top<0){
                
                return true;
            }

            return false;
        }

        void push (char c ,char* q , int size){

            if(top>=size-1){
                cout<<"Stack Overflow! The stack is currently full.";
            }

            else{
                q[++top] = c;
            }

        }


        void push (float f ,float* q , int size){

            if(top>=size-1){
                cout<<"Stack Overflow! The stack is currently full.";
            }

            else{
                q[++top] = f;
            }

        }

        char pop (char* q){
            if(this->isEmpty()){ return '\0';}

            else{
                return q[top--];
            }
        }

        float pop (float* q){
            if(this->isEmpty()){return '\0';}

            else{
                return q[top--];
            }
        }


        bool higher_precedence_operator (char d){
            bool higher_precedence = false;
            int char_value = 0;
            int top_value = 0;

            if(d == '^'){
                char_value = 3;
            }

            else if(d == '*' || d == '/' || d == '%'){
                char_value = 2;
            }

            else if(d == '+' || d == '-'){
                char_value = 1;
            }



            if(stack[top] == '^'){
                top_value = 3;
            }

            else if(stack[top] == '*' || stack[top] == '/' || stack[top] == '%'){
                top_value = 2;
            }

            else if(stack[top] == '+' || stack[top] == '-'){
                top_value = 1;
            }


            if((char_value>top_value) || (char_value == 3 && top_value == 3)){
                higher_precedence = true;
            }
            else{
                higher_precedence = false;
            }

            return higher_precedence;

        }
        
        void converting_to_postfix(char* p , int arr_size){
            for(int i=0; i<arr_size; i++){

                if(p[i] == ' '){
                    continue;
                }

                else if(p[i] == '(' || p[i] == '{' || p[i] == '[' ){
                    push(p[i],stack, stack_size);
                }

                else if(p[i] == ')' || p[i] == '}' || p[i] == ']' ){

                    if(p[i] == ')'){
                        while(!isEmpty() && stack[top] != '('){
                            postFix_output += pop(stack);
                            postFix_output += ' ';
                            
                        }
                    }

                    else if(p[i] == '}'){
                        while(!isEmpty() && stack[top] != '{'){
                            postFix_output += pop(stack);
                            postFix_output += ' ';
                            
                        }
                    }

                    else{
                        while(!isEmpty() && stack[top] != '['){
                            postFix_output += pop(stack);
                            postFix_output += ' ';
                        }
                    }
                    pop(stack); //popping the opening brackets 

                }

                else if(p[i] == '+' || p[i] == '-' || p[i] == '*' || p[i] == '/' || p[i] == '%' || p[i] == '^' ){
                    bool repeat = true;
                    while(repeat){
                        if(isEmpty()){
                            push(p[i],stack,stack_size);
                            repeat =false;
                        }

                        else if(stack[top] == '(' || stack[top] == '{'  || stack[top] == '['){
                            push(p[i],stack, stack_size);
                            repeat = false;
                        }

                        else if(stack[top] == '^' || stack[top] == '*'  || stack[top] == '/' || stack[top] == '%' || stack[top] == '+' || stack[top] == '-'){
                            
                            
                                if(higher_precedence_operator(p[i])){
                                    push(p[i],stack, stack_size);
                                    repeat = false;
                                }

                                else{
                                    postFix_output += pop(stack);
                                    postFix_output += ' ';
                                
                                    repeat = true;
                                    
                                }
                            

                        }
                    }
                }

                else{
                    postFix_output += p[i];
                    
                    
                    while((i+1 < arr_size) && (isdigit(p[i+1]))){
                        i++;
                        postFix_output += p[i];
                    }
                    postFix_output += ' ';
                    
                }

                if(i == arr_size-1){
                    while(!isEmpty()){
                        postFix_output += pop(stack);
                        postFix_output += ' ';
                    }
                }
            }
        
        


        }


        
        float postfix_evaluation (){
            float result = 0;
            top = -1;
            float number_stack[postFix_output.length()];
            for(int j = 0; j<postFix_output.length(); j++){

                if(!isEmpty() || j==0){

                    if(postFix_output[j] == ' '){
                    continue;
                }

                    else if(postFix_output[j] == '^'){

                        if(top<1){
                            cout<<"Syntax error. Error Code: ";
                            return -676767.67;
                        }
                        float temp1 = pop(number_stack);
                        float temp2 = pop(number_stack);

                        result = pow(temp2,temp1);

                        push(result , number_stack , postFix_output.length());
                    }

                    else if(postFix_output[j] == '%'){
                        if(top<1){
                            cout<<"Syntax error. Error Code: ";
                            return -676767.67;
                        }
                        float temp1 = pop(number_stack);
                        float temp2 = pop(number_stack);

                        result = fmod(temp2,temp1);

                        push(result , number_stack , postFix_output.length());
                    }
                    

                    else if(postFix_output[j] == '/'){
                        if(top<1){
                            cout<<"Syntax error. Error Code: ";
                            return -676767.67;
                        }
                        float temp1 = pop(number_stack);
                        float temp2 = pop(number_stack);

                        result = temp2/temp1;

                        push(result , number_stack , postFix_output.length());
                    }

                    else if(postFix_output[j] == '*'){
                        if(top<1){
                            cout<<"Syntax error. Error Code: ";
                            return -676767.67;
                        }
                        float temp1 = pop(number_stack);
                        float temp2 = pop(number_stack);

                        result = temp2*temp1;

                        push(result , number_stack , postFix_output.length());
                    }

                    else if(postFix_output[j] == '+'){
                        if(top<1){
                            cout<<"Syntax error. Error Code: ";
                            return -676767.67;
                        }
                        float temp1 = pop(number_stack);
                        float temp2 = pop(number_stack);

                        result = temp2+temp1;

                        push(result , number_stack , postFix_output.length());
                    }

                    else if(postFix_output[j] == '-'){
                        if(top<1){
                            cout<<"Syntax error. Error Code: ";
                            return -676767.67;
                        }
                        float temp1 = pop(number_stack);
                        float temp2 = pop(number_stack);

                        result = temp2-temp1;

                        push(result , number_stack , postFix_output.length());
                    }

                    else{
                        float result1 = 0;
                        while(postFix_output[j]!= ' '){
                            char v = postFix_output[j];
                            float val = (float)(v - '0');

                            result1 = (result1*10)+ val;
                            j++;
                        }
                            
                        push(result1,number_stack,postFix_output.length());

                    }
                    
                    

                }


                else{
                    cout<<" Code -111111.11: Postfix is empty.";
                    return -111111.11;
                }

                
            }

            
            return pop(number_stack);
        }
        
    




};




int main(){

    while(true){
        string infix ="";

        cout<<"Enter an expression: ";
        getline(cin,infix);
        cout<<"Infix: "<<infix<<endl;
        
        BasicCalculator obj1 = BasicCalculator();
        obj1.converting_to_postfix(&infix[0],infix.length());

        cout<< "Postfix: "<<obj1.postFix_output<<endl;

        cout<<"Result of given expression/Evaluated Postfix: "<<obj1.postfix_evaluation()<<endl;

        cout<<"Exit?(y/n): ";
        char ask;
        cin>>ask;
        if(ask == 'y' || ask == 'Y'){
            cin.ignore(10000, '\n');
            break;
            
        }

        cin.ignore(10000, '\n');
    }


    return 0;
}

