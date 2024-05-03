#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};

struct Node* head;
void print(){
     Node* temp=head;
     while(temp!=NULL)  //the code runs infinite when temp->next!=NULL
     {
        cout<<temp->data<<" ";
        temp=temp->next; 

     }
     cout<<endl;
}
void insert(int data,int n){
      Node* temp1=new Node();
      temp1->data=data;
      temp1->next=NULL;
      if(n==1){ //if n is the position inserting at begnning 
      temp1->next=head;
      head=temp1; 
      return;
      }
      Node *temp2=head; //for traversing the nodes we create temp2
      for(int i=0;i<n-2;i++){
        temp2=temp2->next; //temp2->next will give the address of the next node 
      }
      temp1->next=temp2->next;
      temp2->next=temp1;
}
int main(){
    head=NULL;
    insert(2,1);//List is 2
    insert(3,2);//List is 2 3
    insert(4,1);//list is 4 3 2 
    insert(5,2);//list is 4 5 3 2 
    insert(10,3);
    print();
    for(int i=0;i<0;i++)cout<<"hello"<<endl;

}