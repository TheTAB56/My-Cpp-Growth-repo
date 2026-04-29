#include <iostream>
using namespace std;

int main(){
    
    int arr[10] ={ 5,8,7,9,2,4,3,2,1,0};

    for(int i = 0; i<9; i++){
        bool got_swapped = false;
        for(int j=0; j<9-i; j++){ // the largest number bubbles to the end in each i loop , so we shouldnt count the last place index hence j<9-i
            if(arr[j+1]<arr[j]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                got_swapped = true;
            }
        }

        if(got_swapped == false){
            break;
        }
    }

    for(int i= 0; i<10; i++){
    cout<<arr[i]<<" ";
}
    return 0;
}