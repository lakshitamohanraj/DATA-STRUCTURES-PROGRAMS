#include <iostream>
//priority queue -> order( lowest priority to highest priority)
using namespace std;

struct Node{
    int data;
    int priority;
    Node* next;
};
Node* front=NULL;

void enq(int data,int priority){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->priority=priority;
    newnode->next=nullptr;
    //for inserting 1st node and 2nd node
    if(front==nullptr || priority < front->priority){
        newnode->next=front; //less the priority , front the node ,add as 1st node
        front=newnode;
    }
 // for inserting after two nodes arranged in order
    else{
         Node* temp=front;
/*o(n)*/      while(temp->next!=nullptr && temp->next->priority <=priority){//find the correct position after which newnode can be inserted
            temp=temp->next;
         } 
         newnode->next=temp->next;
         temp->next=newnode;
    }

}


void deq(){
    Node* firstNode=front;
    if(firstNode!=nullptr){
        front=front->next;
        free(firstNode);
    }
    else cout<<"queue underflow"<<endl;
}

void display(){
    Node* temp=front;
    if(temp==NULL) cout<<"queue is EMpty"<<endl;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    
}
int main(){
     enq(10,1);
     enq(-5,0);
     enq(30,3);
     enq(20,2);
     deq();
     display();

    return 0;
}


