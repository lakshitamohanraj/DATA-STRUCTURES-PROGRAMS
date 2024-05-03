#include <iostream>
using namespace std;

struct Node{
    int data;  //4
    char age;
    struct Node* prev;  //4 bytes
    struct Node* next;   //4 bytes
};
struct Node* head;
struct Node* tail;

struct Node* getNewNode(int x)
{ 
    struct Node* newNode=new Node();//creating node at heap  //(struct Node*)malloc(sizeof(struct Node))

    newNode->data=x;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
     
}
void insertAtHead(int num){
    struct Node* newNode=getNewNode(num);
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
        return ;
    }  
    head->prev=newNode;
    newNode->next=head;
    head=newNode;    
}
void insertAtTail(int num){
    struct Node* newNode=getNewNode(num);
    // cout<<newNode<<endl;
   if(head==NULL){
        head=newNode;
        tail=newNode; //tail stays at the last node 
        return;
   }

   tail->next=newNode; 
   newNode->prev=tail; 
   tail=newNode;
}

void insertAtPosition(int pos,int num)
{
    struct Node* newNode=getNewNode(num);
    struct Node* temp=head;
    for(int i=0;i<pos-2;i++){
        temp=temp->next;   //n-1 th node that is pos-1
    }

    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
    // struct Node* temp2=temp->next;//points to nth node
    // temp->next=newNode;
    // temp2->prev=newNode;
    // newNode->prev=temp;
    // newNode->next=temp2;

}


void insertAtBeforeNode(int num,int mid_data){
    struct Node* newnode=getNewNode(num);
    struct Node* temp=head;
    for(;temp!=NULL;temp=temp->next)
    {
        if(temp->data==mid_data){
            break;
        }
    }
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp; 
}

void printForward(){
    cout<<"print forward :";
    struct Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next; //forward printing
    }
}
void printReverse(){
    struct Node* temp=tail;
    // if(temp==NULL) return;//list is empty exit
    // //going to last node
    // while(temp->next!=NULL){
    //     temp=temp->next;
    // }
    //traversing backward now
    cout<<" Reverse :";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev; //goes backwards
    }
    cout<<endl;
}

int main(){
   head=NULL;
   insertAtHead(12);printForward();printReverse();
   insertAtHead(23);printForward();printReverse();
   insertAtHead(89);printForward();printReverse();
   insertAtHead(90);printForward();printReverse();
   insertAtTail(100);printForward();printReverse();  //how is this possible ? u got the ans
   insertAtPosition(3,200);printForward();printReverse();
   insertAtBeforeNode(150,12);
   printForward();
cout<<"  "<<endl;
// cout<<sizeof(Node)<<endl;
// // cout<<sizeof(int)<<endl;
// // cout<<sizeof(char)<<endl;
// // cout<<sizeof(struct Node*prev)<<endl;

}
