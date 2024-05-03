#include<iostream>
using namespace std;
// push()//pushing at the top of the stack
//  / check if the stack is full or not , if full display overflow_error, else push the element into the stack incremenht the listSize by 1
//pop()//deletion at the end of the stack
// check if the stack is empty or not ,if empty display underflow_error ,else delete the last element and reduce the listSize by 1
#define MAXSIZE 5
int listSize=0;
class Node{
    public:
      int data;
      Node * nextnodelink;
};
Node *head=NULL;
Node* tail=NULL;
Node *getNewNode(int value){
    
    Node*newnode= new Node();
    newnode->data=value;
    newnode->nextnodelink=nullptr;
    return newnode;

}
void push(int value)
{
    Node *newnode=getNewNode(value);
    if(head==NULL && tail==NULL){

        head=newnode;
        tail=newnode;
        listSize++;
    }
    else if(head!=NULL && listSize<=5){
         newnode->nextnodelink=head;
         head=newnode;
         listSize++;
    }
    else {
        cout<<"Overflow Stack Error"<<endl;
    }
    
      
}
void pop()
{
    if(head->nextnodelink==NULL){
        cout<<"Underflow Stack Error"<<endl;
    } 
    else{
        Node* temp=head;
        cout<<"Deleted element is: "<<temp->data;
        head=head->nextnodelink;
        free(temp);
        listSize--; 
    }
}
void display(){
   if(head->nextnodelink==NULL){
    cout<<"Stack is EMpty"<<endl;
   }
   else{
    Node* temp=head;
    while(temp->nextnodelink!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->nextnodelink;
    }
   }
}
int main()
{

 push(10);
 display();

 return 0;
}