#include <iostream>
using namespace std;

void selection_sort(int* p , int size_of_arr){ // pass &arr[0] from main
    

    for(int i =0; i<size_of_arr-1; i++){
        int k = i ;
        for(int j = i+1; j<size_of_arr; j++ ){
            if(p[j]< p[k]){
                k = j;
            }
        }
        int temp = 0;
        temp = p[i];
        p[i] = p[k];
        p[k] = temp;
    }


}


void insertion_sort(int* p , int size_arr){
    
    for(int i = 1; i<size_arr; i++){
        
        int v = p[i];
        int j = i-1;

        while(j>=0 && p[j]>v){
            p[j+1] = p[j];
            j--;
        }
        p[j+1]= v;
        /*for(int j =i-1; j>=0;j--){
            if(v<p[j]){
                p[j+1]=p[j];
                if(j==0){
                    p[j]=v;
                }
            }

            else{
                p[j+1]=v;
                break;
            }
        }*/
    }
}

void bubble_sort(int* p , int size_of_arr){

    for(int i=0; i<size_of_arr-1;i++){
        bool flag = false;
        for(int j=0; j<size_of_arr-1-i; j++){
            if(p[j+1]<p[j]){
                int temp = 0;
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
                flag = true;
            }
           
        }
        if(flag == false){
            break;
        }
    }
}

void binary_search(int* p , int target , int size_arr){
    int start = 0;
    int end = size_arr-1;
    bool target_found =false;
    while(start<=end){
        int middle = (start+end)/2;

        if(p[middle]<target){
            start = middle+1;
        }

        else if (p[middle] == target){
            cout<<"Your target "<<target<<" was at index no: "<<middle<<endl;
            target_found = true;
            break;
        }

        else if (p[middle]>target){
            
            end = middle-1;
        }

    }
    if(target_found == false){
        cout<<"Searched target is not present in this array."<<endl;
    }
}



int main(){

    int size_arr = 11;
    int arr[size_arr] ={ 5,8,7,9,2,4,3,12,2,1,0};

    bubble_sort(&arr[0] , size_arr);
    
    selection_sort(arr , size_arr);

    insertion_sort(arr , size_arr);


    for(int i= 0; i<size_arr; i++){
    cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    cout<<"Enter target: ";
    int target = 0;
    cin>>target;
    
    binary_search(arr , target , size_arr);
    

    return 0;

}