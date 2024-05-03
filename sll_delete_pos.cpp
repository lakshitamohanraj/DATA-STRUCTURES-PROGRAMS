#include <iostream>
using namespace std;

struct Node{
   int data;
   struct Node* next; //pointer to objects
};
Node* head;
Node* tail;
void insert(int num){ //insert at the end of the list
    Node* temp=new Node();
    temp->data=num;
    temp->next=NULL;
    struct Node* temp1=head;
    if(head==NULL){
        head=temp;
        tail=temp;
    }
    else{
    tail->next=temp;
    tail=temp;
    }

}
void print(){
    struct Node* temp=head;
    while(temp!=NULL){
         cout<<temp->data<<" ";
         temp=temp->next;
    }
}
void Delete_pos(int pos){
      struct Node* temp1=head;
      if(pos==1) //deleting head node
      {
          head=temp1->next;
          // temp1->next=NULL;
          free(temp1); 
          return ;
      }
      //else
      for(int i=0;i<pos-2;i++){
        temp1=temp1->next;
      }
      struct Node* temp2=temp1->next;//pos nth node
      temp1->next=temp2->next;  //n+1 th node
      free(temp2);//delete temp2;

}


int main(){
  head=NULL;
  insert(12);
  insert(10);
  insert(90);
  insert(19);
  cout<<"before deletion"<<endl;
  print();
  Delete_pos(1);
  Delete_pos(3);
  insert(130);
  cout<<"after deletion"<<endl;
  print();
  return 0;
}