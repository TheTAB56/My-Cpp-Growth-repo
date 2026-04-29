#include <iostream>
using namespace std;

int main(){
    int arr[10] ={ 5,8,7,9,2,4,3,2,1,0};


for (int i = 0; i<9 ; i++){
    int k = i;
    for(int j = i+1; j<10; j++){
        if(arr[j]<arr[k]){
            
            k = j;
        }
        
    }
    int temp =0;
        temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
}
for(int i= 0; i<10; i++){
    cout<<arr[i]<<" ";
}

return 0;
}