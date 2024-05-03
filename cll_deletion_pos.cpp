#include <iostream>
using namespace std;
struct Node{
   int data;
   struct Node* next;
};
Node* tail;

void insert(int num){//insertion at the end
  Node* newnode=new Node();
  newnode->data=num;
  newnode->next=NULL;
  if(tail==NULL)
  {
    tail=newnode;
    newnode->next=tail;
    return ;
  }
  newnode->next=tail->next;
  tail->next=newnode;
  tail=newnode;
}

void DeleteAtHead(){
   Node* temp=tail->next;
   tail->next=temp->next;
   free(temp);
}
void DeleteAtTail(){
  Node* temp=tail->next;
  while(temp->next!=tail)
  {
    temp=temp->next;
  }
  temp->next=tail->next;
  free(tail);
  tail=temp;
}

void DeleteAtPosition(int pos){
    Node* temp=tail->next;
    for(int i=0;i<pos-2;i++){ //previous node of pos
        temp=temp->next;
    }
    Node* temp2=temp->next;
    if(temp2==tail){
        temp->next=temp2->next;
        tail=temp;
        free(temp2);
        return ;
    }
    temp->next=temp2->next;
    free(temp2);

}
void printForward()
{
    Node* temp=tail->next;
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
    insert(12);
    insert(13);
    insert(145);
    insert(100);
    insert(109);
    insert(134);
    printForward();
    DeleteAtHead();
    DeleteAtTail();
    printForward();
     DeleteAtPosition(2);
   printForward();
   DeleteAtPosition(3);
   printForward();
    return 0;
    }