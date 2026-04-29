#include <iostream>
#include <string>
using namespace std;


struct fooditem{
    string item_name;
    int amount;
    int price;


};

int total_price(fooditem i){
        return i.amount*i.price;}
int main(){




    

    
fooditem number_of_items[500];

cout<< "                 -----Welcome to Mehtab's Restaurant------"<<endl;


cout<<"Please type the number of items of dishes you'd like to order: ";
int dishes = 0;
cin>> dishes;
cout<<endl;
int sum = 0;
for(int i =0; i<dishes; i++){
    cout<< "Please type your dish name here: ";
    cin>> number_of_items[i].item_name;
    cout<<endl;
    cin.ignore();
    cout<<"How many plates of this dish you'd like,Sir: ";
    cin>>number_of_items[i].amount;
    cout<<"The price of this dish is 120 BDT"<<endl;
    number_of_items[i].price = 120;
    sum += total_price(number_of_items[i]);
}

cout<<"Your total price = "<<sum;

    return 0;
}