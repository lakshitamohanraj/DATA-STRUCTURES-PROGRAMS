#include <iostream>
using namespace std;

struct Node{
   int data;
   struct Node* prev;
   struct Node* next;
};

struct Node* head;
struct Node* tail;
  
struct Node* getNewNode(int x)
{ 
    struct Node* newNode=new Node();//creating node at heap 
    newNode->data=x;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
     
}  

void insert(int num){ //insertion at the end
  struct Node* newNode=getNewNode(num);
  if(head==NULL){
    head=newNode;
    tail=newNode;
    return;
  }
  tail->next=newNode;
  newNode->prev=tail;
  tail=newNode;

}
void DeleteAtHead(){
    struct Node* temp=head;
    head=temp->next;
    head->prev=NULL;
    free(temp);
    // struct Node* previousNode=temp->next;
}
void DeleteAtTail(){
   struct Node* temp=tail;
  //  struct Node* beforetail=temp->prev;
  //  temp->prev->next=NULL;
  //  temp->prev=NULL;
  //  tail=temp;
  //  temp->prev=NULL;
   temp->prev->next=NULL;
   tail=temp->prev;
   temp->prev=NULL;
   free(temp);
}
void DeleteAtPosition(int pos){
  struct Node* temp=head;
  //to go to n-1 th node
  // for(int i=0;i<pos-2;i++){
  //   temp=temp->next;
  // }
  // struct Node* temp2=temp->next;//nth node 
  // temp->next=temp2->next;
  // (temp2->next)->prev=temp;
  // temp2->next=temp2->prev=NULL;
  // free(temp2);


  for(int i=0;i<pos-1;i++){
    temp=temp->next;
  }
  temp->prev->next=temp->next;
  temp->next->prev=temp->prev;
  temp->prev=temp->next=NULL;
  free(temp);

}

void DeleteAtNode(int mid_data){
  Node* temp=head;
  for(;temp!=NULL;temp=temp->next){
    if(temp->data==mid_data) break;
  }
  temp->prev->next=temp->next;
  temp->next->prev=temp->prev;
  temp->prev=NULL;
  temp->next=NULL;
  free(temp);
}
void printForward()
{
    cout<<" Forward :" ;
    struct Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next; //forward printing
    }
    
}
void printReverse()
{
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
  insert(100);
  insert(200);
  insert(300);
  insert(400);
  insert(500);
  insert(600);
  DeleteAtHead();
  printForward();printReverse();
  DeleteAtTail();
  printForward();printReverse();
  DeleteAtPosition(3);
  printForward();printReverse();
  DeleteAtNode(300);
  printForward();printReverse();
    return 0;
}