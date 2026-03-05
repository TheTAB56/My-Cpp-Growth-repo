#include <iostream>
using namespace std;

int main(){

    int rows = 3;
    int col = 3;

    int a[rows][col];

    for(int i=0; i<rows;i++){
        for(int j=0;j<col;j++){
            cout<<"Input Number in row "<<i+1<<" and coloumn "<<j+1<<": ";
            cin>>a[i][j];
        }
    }

    cout<<"Original matrix: "<<endl;
    for(int i=0; i<rows;i++){
        for(int j=0;j<col;j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    

    
    cout<<"\nTranspose matrix(without saving what's getting printed): "<<endl;

    for(int j = 0; j<col; j++){
        for(int i = 0; i<rows; i++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }





    int trans_rows = col;
    int trans_col = rows;

    int transpose_matrix [trans_rows][trans_col];

    for(int j=0; j<col; j++){
        for(int i =0; i<rows; i++){
            transpose_matrix[j][i] = a[i][j];
        }
    }

    cout<<endl;
    cout<<"Transpose matrix(saving the printed result): "<<endl;

    for(int i=0; i<trans_rows;i++){
        for(int j=0;j<trans_col;j++){
            cout<<transpose_matrix[i][j]<<"\t";
        }
        cout<<endl;
    }


    //Adding diagonals
    int sum = 0;
    for(int i=0; i<trans_rows; i++){
        for(int j = 0; j<trans_col; j++){
            if(i == j){
                sum+= transpose_matrix[i][j];
            }
        }
    }
    cout<<"Sum of the diagonal elements of transpose matrix is = "<<sum<<endl;

    //Adding Opposite diagonal
    int total = 0;
    int temp_row = 0;
    int temp_col = col-1;

    for(int i =0;i<rows;i++){
        for(int j =0; j<col; j++){
            if(temp_col==j){
                total+= a[i][j];
                temp_col--;
            }
        }
    }
    cout<<"\nSum of the Opposite diagonal elements of original matrix is = "<<total<<endl;

    //more efficient way to calculate opposite diagonal
    /*for(int i = 0; i < rows; i++) {
                                            // In a 3x3, this visits (0,2), (1,1), (2,0)
        total += a[i][col - 1 - i]; 
    }*/


    //Searching a target or key in a 2d array 
    bool isFound = false;
    cout<<"Your target: ";
    int target;
    cin>>target;
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<col; j++){
            if(target == a[i][j]){
                isFound = true;
                cout<<target<<" has been found in row: "<<i+1<<" and coloumn: "<<j+1<<" of the original matrix";
                break;
            }
        }
        if(isFound){
            break;
        }
    }

    if(isFound == false){
        cout<<target<<" was not found in the array.";
    }


    //matrix multiplication ,mat 1 is a and mat 2 is transpose of a
    int mat1xmat2[rows][trans_col];
    if(col == trans_rows){
        

        for(int i = 0; i<rows; i++){
            for(int j=0; j<trans_col; j++){
                int sum = 0;
                for(int k =0; k<trans_rows; k++){
                    sum += a[i][k]*transpose_matrix[k][j];
                }
                mat1xmat2[i][j] = sum;
            }
        }
    }

    else{
        cout<<"Since 1st matrix's coloumn count and 2nd matrix's row count arent equal ,hence multiplication between them is not possible.";
    
    }

    cout<<"\nMultiplied matrix: "<<endl;
    for(int i=0; i<rows;i++){
        for(int j=0;j<trans_col;j++){
            cout<<mat1xmat2[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"Addition of matrix: "<<endl;
    if(rows == trans_rows && col == trans_col){
        
    for(int i=0; i<rows;i++){
        for(int j=0;j<col;j++){
            cout<<a[i][j]+transpose_matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    }
    else{
        cout<<"Matrices can only be added or subtracted if both matrices have equal number of rows and equal number of coloumns.";
    }
    return 0;
}

