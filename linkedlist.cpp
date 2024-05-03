#include <iostream>
using namespace std;
struct Node{
  int data;
  Node *next;
};
Node * head;  //(pointer to objects)hat is to point struct variables 

void print()
{
     struct Node *temp1=head;
     while(temp1!=NULL){
        cout<<temp1->data<<" ";
        temp1=temp1->next;
     }
}
void insert(int x){
     struct Node * temp1=head;//for traversing the list
     while(temp1->next!=NULL){
        temp1=temp1->next;
     }
     Node *newnode=new Node();
    (*newnode).data=x;
    temp1->next=newnode;//here newnode is a pointer that holds the address of newly created node for insertion
}
int main(){
    head=NULL;
    Node * temp=new Node();
    temp->data=223;
    temp->next=NULL; 
    head=temp;//just like px=py (pointer to x =pointer y)=> pointer x changes
    temp=new Node();
    temp->data=2334;
    temp->next=NULL;
    head->next=temp;   //pointer next pointes to temp that is 2nd node (temp basically holdes the address of 2nd node here)
    int x;
    cout<<"enter the data to be inserted at the end of list"<<endl;
    cin>>x;
    insert(x);
    print();

}
