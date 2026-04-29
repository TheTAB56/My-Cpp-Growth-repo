#include <iostream>
using namespace std;


class Node{
    private:
        int data;
        Node* prevAd;
        Node* nextAd;
    
    public:
        Node(int x){
            data = x;
        }

        void swap(Node* p1 , Node* p2 ){
            Node* tempPrevp1;
            Node* tempNextp1;

            extern Node* HeadNode;
            extern Node* TailNode;
            
            if(p1->prevAd == nullptr){

                if(p1->nextAd == p2){

                    if(p2->nextAd == nullptr){
                        p2->nextAd = p2->prevAd;
                        p2->prevAd = nullptr;

                        p1->prevAd = p1->nextAd;
                        p1->nextAd = nullptr;

                        HeadNode = p2;
                        TailNode = p1;
                    }
                    
                    else{
                        (p2->nextAd)->prevAd = p1;

                        tempPrevp1 = p1->prevAd;
                        tempNextp1 = p2;

                        p1->prevAd = p2;
                        p1->nextAd = (*p2).nextAd; 

                        p2->prevAd = tempPrevp1;
                        p2->nextAd = p1;

                        HeadNode = p2;
                    }

                }

                else if(p2->nextAd == nullptr){

                    (p1->nextAd)->prevAd = p2;
                    (p2->prevAd)->nextAd = p1;

                    tempPrevp1 = p1->prevAd;
                    tempNextp1 = p1->nextAd;

                    p1->prevAd = p2->prevAd;
                    p1->nextAd = (*p2).nextAd; 

                    p2->prevAd = tempPrevp1;
                    p2->nextAd = tempNextp1;

                    HeadNode = p2;
                    TailNode = p1;
                }

                else{
                    
                    (p1->nextAd)->prevAd = p2;

                    (p2->prevAd)->nextAd = p1;
                    (p2->nextAd)->prevAd = p1;




                    tempPrevp1 = p1->prevAd;
                    tempNextp1 = p1->nextAd;

                    p1->prevAd = p2->prevAd;
                    p1->nextAd = (*p2).nextAd; //jus showcasin what -> actually means  goes to tempPrevp1's address, pulls out/derefences the object then does object.prevAd and pulls out the value inside

                    p2->prevAd = tempPrevp1;
                    p2->nextAd = tempNextp1;

                    HeadNode = p2;

                }


            }

            else if(p2->prevAd == nullptr){

                if(p2->nextAd == p1){

                    if(p1->nextAd == nullptr){
                        p1->nextAd = p1->prevAd;
                        p1->prevAd = nullptr;

                        p2->prevAd = p2->nextAd;
                        p2->nextAd = nullptr;

                        HeadNode = p1;
                        TailNode = p2;
                    }
                    else{
                        (p1->nextAd)->prevAd = p2;

                        tempPrevp1 = p2->prevAd;
                        tempNextp1 = p1;

                        p2->prevAd = p1;
                        p2->nextAd = (*p1).nextAd; 

                        p1->prevAd = tempPrevp1;
                        p1->nextAd = p2;

                        HeadNode = p1;
                    }

                }

                else if(p1->nextAd == nullptr){

                    (p2->nextAd)->prevAd = p1;
                    (p1->prevAd)->nextAd = p2;

                    tempPrevp1 = p1->prevAd;
                    tempNextp1 = p1->nextAd;

                    p1->prevAd = p2->prevAd;
                    p1->nextAd = (*p2).nextAd; 

                    p2->prevAd = tempPrevp1;
                    p2->nextAd = tempNextp1;

                    HeadNode = p1;
                    TailNode = p2;
                }

                else{
                    
                    (p2->nextAd)->prevAd = p1;

                    (p1->prevAd)->nextAd = p2;
                    (p1->nextAd)->prevAd = p2;




                    tempPrevp1 = p1->prevAd;
                    tempNextp1 = p1->nextAd;

                    p1->prevAd = p2->prevAd;
                    p1->nextAd = (*p2).nextAd; //jus showcasin what -> actually means  goes to tempPrevp1's address, pulls out/derefences the object then does object.prevAd and pulls out the value inside

                    p2->prevAd = tempPrevp1;
                    p2->nextAd = tempNextp1;

                    HeadNode = p1;

                }
            }





            else if(p1->nextAd == nullptr){

                if(p1->prevAd == p2){

                    (p2->prevAd)->nextAd = p1;

                    tempPrevp1 = p1->prevAd;
                    tempNextp1 = p1->nextAd;

                    p1->prevAd = p2->prevAd;
                    p1->nextAd = (*p2).nextAd; 

                    p2->prevAd = tempPrevp1;
                    p2->nextAd = tempNextp1;

                    TailNode = p2;

                }


                else{
                    
                    (p1->prevAd)->nextAd = p2;

                    (p2->prevAd)->nextAd = p1;
                    (p2->nextAd)->prevAd = p1;




                    tempPrevp1 = p1->prevAd;
                    tempNextp1 = p1->nextAd;

                    p1->prevAd = p2->prevAd;
                    p1->nextAd = (*p2).nextAd; //jus showcasin what -> actually means  goes to tempPrevp1's address, pulls out/derefences the object then does object.prevAd and pulls out the value inside

                    p2->prevAd = tempPrevp1;
                    p2->nextAd = tempNextp1;

                    TailNode = p2;

                }
            }


            else if(p2->nextAd == nullptr){


                if(p2->prevAd == p1){

                    (p1->prevAd)->nextAd = p2;

                    tempPrevp1 = p1;
                    tempNextp1 = p2->nextAd;

                    p2->prevAd = p1->prevAd;
                    p2->nextAd = p1; 

                    p1->prevAd = p2;
                    p1->nextAd = tempNextp1;

                    TailNode = p1;

                }

                else{
                    
                    (p2->prevAd)->nextAd = p1;

                    (p1->prevAd)->nextAd = p2;
                    (p1->nextAd)->prevAd = p2;




                    tempPrevp1 = p1->prevAd;
                    tempNextp1 = p1->nextAd;

                    p1->prevAd = p2->prevAd;
                    p1->nextAd = (*p2).nextAd; //jus showcasin what -> actually means  goes to tempPrevp1's address, pulls out/derefences the object then does object.prevAd and pulls out the value inside

                    p2->prevAd = tempPrevp1;
                    p2->nextAd = tempNextp1;

                    TailNode = p1;
                }

                
            }


            else{

                if(p1->nextAd == p2){

                    (p1->prevAd)->nextAd = p2;
                    (p2->nextAd)->prevAd = p1;


                    tempPrevp1 = p1->prevAd;
                    tempNextp1 = p2;

                    p1->prevAd = p2;
                    p1->nextAd = (*p2).nextAd; //jus showcasin what -> actually means  goes to tempPrevp1's address, pulls out/derefences the object then does object.prevAd and pulls out the value inside

                    p2->prevAd = tempPrevp1;
                    p2->nextAd = p1;

                }

                else if(p2->nextAd == p1){

                    (p2->prevAd)->nextAd = p1;
                    (p1->nextAd)->prevAd = p2;


                    tempPrevp1 = p2->prevAd;
                    tempNextp1 = p1;

                    p2->prevAd = p1;
                    p2->nextAd = (*p1).nextAd; //jus showcasin what -> actually means  goes to tempPrevp1's address, pulls out/derefences the object then does object.prevAd and pulls out the value inside

                    p1->prevAd = tempPrevp1;
                    p1->nextAd = p2;

                }

                else{
                    (p1->prevAd)->nextAd = p2;
                    (p1->nextAd)->prevAd = p2;

                    (p2->prevAd)->nextAd = p1;
                    (p2->nextAd)->prevAd = p1;




                    tempPrevp1 = p1->prevAd;
                    tempNextp1 = p1->nextAd;

                    p1->prevAd = p2->prevAd;
                    p1->nextAd = (*p2).nextAd; //jus showcasin what -> actually means  goes to tempPrevp1's address, pulls out/derefences the object then does object.prevAd and pulls out the value inside

                    p2->prevAd = tempPrevp1;
                    p2->nextAd = tempNextp1;
                }
            }
    
        }    

};

Node* HeadNode = nullptr;
Node* TailNode = nullptr;


void selection_sort(int target){



}