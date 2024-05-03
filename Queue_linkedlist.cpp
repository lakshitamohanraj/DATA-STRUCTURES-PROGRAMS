#include<iostream>
using namespace std;
//QUEUE IMPLEMENTATION USING LINKED LIST
//Single linked list
//the complexity of the enqueue and dequeue in linked list is o(1) constant
struct Node{
    int data;
    Node* next;
};
Node* front;
Node* rear;
bool isEmpty(){

}
void enqueue(int data){ //insertion at the end rear
   Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
   newnode->next=NULL;
   if(front==nullptr && rear==nullptr){ //or front==0 and rear==0
        front=newnode;
        rear=newnode;
   }
   else{
     rear->next=newnode;
     rear=newnode;
   }

}
void dequeue(){ //deletion at the front 
     if(front!=nullptr){
         struct Node* firstNode=front;
         front=front->next;
         cout<<"Deleted element :"<<firstNode->data<<endl;
         free(firstNode); //deleting the front value
     }

}
void peek(){
   if(front!=nullptr){
    cout<<front->data<<" ";
   }
   else cout<<"Queue is empty"<<endl;
}
void display(){
    struct Node* temp=front;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}

int main(){
    enqueue(13);
    enqueue(45);
    enqueue(145);
    enqueue(178);
    display();
    dequeue();
    display();


    return 0;
}
