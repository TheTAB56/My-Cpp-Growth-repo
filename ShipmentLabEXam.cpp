#include <iostream>
using namespace std;


int main(){

       int size_of_arr = 10;
       int p[size_of_arr];

       cout<<"Please enter the number of shipments for each day below: "<<endl;
       int input =0;
       for(int i=0;i<size_of_arr; i++){
        cout<<"Day "<<i+1<<": ";
        cin>>input;
        cout<<endl;
        p[i] = input;
       }

       cout<<"Unorganized array: ";

       for(int i=0;i<size_of_arr; i++){
                cout<<p[i]<<" ";
       }
       cout<<endl;

       int total_passes = 0;
       int total_swaps = 0;

       for(int i =0; i<size_of_arr-1; i++){
        int k = i ;
        total_passes++;
        bool swap_check = false;
        for(int j = i+1; j<size_of_arr; j++ ){
            if(p[j]> p[k]){
                k = j;
                swap_check = true;
            }
        }
        int temp = 0;
        temp = p[i];
        p[i] = p[k];
        p[k] = temp;
        if(swap_check){
            total_swaps++;
        }

    }
        double mean = 0;
        double sum_of_full_array = 0;
        cout<<"The sorted array in descending order is: ";
        for(int i=0;i<size_of_arr; i++){
                cout<<p[i]<<" ";
                sum_of_full_array+= p[i];
        }

        mean = sum_of_full_array/size_of_arr;

        cout<<endl;
        cout<<"Total passes: "<< total_passes<<endl;
        cout<<"Total swaps: "<< total_swaps<<endl;
        cout<<"Mean: "<< mean<<endl;

       return 0;
       }

