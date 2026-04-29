#include <iostream>
using namespace std;

struct NodeOfSingleLL{

    int data;
    NodeOfSingleLL* nextAd = nullptr;
};

NodeOfSingleLL* Head = nullptr;

NodeOfSingleLL* LinearSearch(int target){

    extern NodeOfSingleLL* Head;

    NodeOfSingleLL* curr = Head;

    while(curr != nullptr){
        if(curr->data == target){
            return curr;
        }
        curr = curr->nextAd;
    }
    cout<<"Target Not found";
    return nullptr;
}

void insertAtFirst(NodeOfSingleLL* Node){
    extern NodeOfSingleLL* Head;

    Node->nextAd = Head;

    Head = Node;
}

void insertAtLast(NodeOfSingleLL* Node){
    extern NodeOfSingleLL* Head;

    NodeOfSingleLL* temp = Head;

    while(true){
        if(temp->nextAd == nullptr){
            temp = temp->nextAd;
            break;
        }
        temp = temp->nextAd;
    }

    temp->nextAd = Node;
    Node->nextAd = nullptr;
}

void insertAtAnyPos(NodeOfSingleLL* Node, int target){

    NodeOfSingleLL* temp = LinearSearch(target);

    NodeOfSingleLL* storage = temp->nextAd;

    temp->nextAd = Node;
    Node->nextAd = storage;

}


void deleteAtFirst(){
    extern NodeOfSingleLL* Head;

    Head = Head->nextAd;
}

void deleteAtLast(){

    NodeOfSingleLL* temp;

    while(true){
        if((temp->nextAd)->nextAd == nullptr){
            break;
        }
        temp = temp->nextAd;
    }

    temp->nextAd = nullptr;
}

void deleteAtAnyPos(int target){
    extern NodeOfSingleLL* Head;

    NodeOfSingleLL* temp = LinearSearch(target);


    NodeOfSingleLL* curr = Head;

    while(curr != nullptr){
        if(Head->data == target){
            break;
        }
        else if((curr->nextAd)->data == target){ //assuming the node with the target is going to be deleted so we need the the node before the target node
            break;
        }
        curr = curr->nextAd;
    }

    curr->nextAd = temp->nextAd;



}



// STARTING OF DOUBLE LINKED LIST



struct NodeOfDLL {

    int data;
    NodeOfDLL* prevAd = nullptr;
    NodeOfDLL* nextAd = nullptr;

};

NodeOfDLL* HeadDll = nullptr;

NodeOfDLL* LinearSearchDll(int target){

    extern NodeOfDLL* HeadDll;

    NodeOfDLL* curr = HeadDll;

    while(curr != nullptr){
        if(curr->data == target){
            return curr;
        }
        curr = curr->nextAd;
    }
    cout<<"Target Not found";
    return nullptr;
}


void insertAtFirst(NodeOfDLL* Node){
    extern NodeOfDLL* HeadDll;

    HeadDll->prevAd = Node;
    Node->nextAd = HeadDll;
    Node->prevAd = nullptr;

    HeadDll = Node;
}

void insertAtLast(NodeOfDLL* Node){
    extern NodeOfDLL* HeadDll;
    
    NodeOfDLL* temp = HeadDll;

    while(true){
        if(temp->nextAd == nullptr){
            break;
        }
        temp = temp->nextAd;
    }

    temp->nextAd = Node;
    Node->prevAd = temp;
    Node->nextAd = nullptr;
}

void insertAtAnyPos(NodeOfDLL* Node , int target){
    extern NodeOfDLL* HeadDll;

    NodeOfDLL* temp = LinearSearchDll(target); //assuming we are inserting after the target node;

    (temp->nextAd)->prevAd = Node;
    Node->nextAd = temp->nextAd;
    Node->prevAd = temp;
    temp->nextAd = Node;

}


void deleteAtFirst(){
    extern NodeOfDLL* HeadDll;

    (HeadDll->nextAd)->prevAd = nullptr;
    HeadDll = HeadDll->nextAd;

}

void deleteAtLast(){


    NodeOfDLL* temp = nullptr;

    while(true){
        if(temp->nextAd == nullptr){
            break;
        }
        temp = temp->nextAd;
    }

    (temp->prevAd)->nextAd = nullptr;
}


void deleteAtAnyPos(int target){
    extern NodeOfDLL* HeadDll;

    NodeOfDLL* temp = LinearSearchDll(target);

    (temp->prevAd)->nextAd = (temp->nextAd);
    (temp->nextAd)->prevAd = temp->prevAd;
}
