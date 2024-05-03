#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head;
Node* tail;


Node* getNewNode(int x){
    Node* newnode=new Node();
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
void insertAtHead(int num){
       Node* newnode=getNewNode(num);
       if(tail==NULL){//why not for head==NULL
        head=newnode;
        tail=newnode;
        newnode->next=tail;
        // head=newnode;
        return;
       }
       newnode->next=tail->next;
       tail->next=newnode;

}
void insertAtPosition(int pos,int num){
    Node* newnode=getNewNode(num);
    Node* temp=tail->next;
    for(int i=0;i<pos-2;i++){//previous node position
        temp=temp->next;
    }
    if(temp==tail){
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    
}
void insertAtTail(int num){
  Node* newnode=getNewNode(num);
  Node* temp=tail;
  newnode->next=tail->next;
  tail->next=newnode;
  tail=newnode; 
}
void printForward()
{
    Node* temp=tail->next;
    // if(temp->next==head) cout<<temp->data<<" ";
    cout<<" Forward :";
    do{
       cout<<temp->data<<" ";
       temp=temp->next;
    }
    while(temp!=tail->next);
    cout<<endl;
}

int main(){
    tail=NULL;
    insertAtHead(12);
    printForward();
    insertAtHead(23);
    printForward();
    insertAtHead(34);
    printForward();
    insertAtHead(24);
    printForward();
    insertAtPosition(3,100);
    printForward();
    insertAtTail(88);
    printForward();
    insertAtPosition(7,900);
    printForward();
    return 0;
}