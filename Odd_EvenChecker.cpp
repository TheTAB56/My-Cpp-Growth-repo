#include <iostream>
using namespace std;

int main(){

    int arr_size = 5;
    int arr[arr_size];
    for(int i = 0; i<arr_size ; i++){
        cout<<"Enter a number to put in position "<<(i+1)<<" : ";
        cin>>arr[i];
    }

    cout<<"\n"<<endl;

    for(int i = 0; i<arr_size; i++){

        if(arr[i]>0){
            if(arr[i]%2 == 0){
                cout<<"Index: "<<(i+1)<<"   Number: "<<arr[i]<<"   Result: Positive Even"<<endl;
            }

            else{
                cout<<"Index: "<<(i+1)<<"   Number: "<<arr[i]<<"   Result: Positive Odd"<<endl;
            }
        }

        else if ( arr[i] == 0){
            cout<<"Index: "<<(i+1)<<"   Number: "<<arr[i]<<"   Result: Zero"<<endl;
        }

        else if ( arr[i] < 0){
            if(arr[i]%2 == 0){
                cout<<"Index: "<<(i+1)<<"   Number: "<<arr[i]<<"   Result: Negative Even"<<endl;
            }

            else{
                cout<<"Index: "<<(i+1)<<"   Number: "<<arr[i]<<"   Result: Negative Odd"<<endl;
            }
        }
    }

}
