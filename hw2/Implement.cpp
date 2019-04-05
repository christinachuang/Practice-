#include <iostream>
#include "Implement.h"
using namespace std;
// add your code here
//------------------------------------------------------
void Implement::InsertBack(int data)
{
    if(this->head){
		Node* now= this->head;
        while(now->next!=NULL){
            now=now->next;
        }
        now->next= new Node(data);
    }
    else{
        this->head= new Node(data);
    }
}
void Implement::InsertAfter(int data1, int data2){
    Node* now= this->head;
    while(now!=NULL){
        if(now->data==data1){
            Node* in= new Node(data2);
            in->next=now->next;
            now->next=in;
        }
        now=now->next;
    }
}
void Implement::Delete(int data){
    Node* now= this->head;
    Node* pre= this->head->next;
    int y=0;
    while(now!=NULL && y==0){
        if(now==this->head && pre==NULL){
            if(now->data==data){
                now=NULL;
            }
            y=1;
        }
        else if(pre->data==data){
            now->next=pre->next;
            y=1;
            delete pre;
            pre = NULL;
        }
        else{
            if(pre->next!=NULL){
                now=now->next;
                pre=pre->next;
            }
            else
                y=1;
        }
    }
}
void Implement::Reverse(){
    Node *current=this->head, *previous= NULL;
    if(this->head!=NULL){
        if(this->head->next!=NULL){
            while(current){
                Node *r= previous;
                previous= current;
                current = current->next;
                previous->next=r;
            }
            Node *temp= this->head;
            this->head=previous;
        }
    }
}
//...

//------------------------------------------------------
