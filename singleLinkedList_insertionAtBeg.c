#include <stdio.h>
#include <stdlib.h>
//if the head is not a global variable then this code will be similar to c 


struct Node
{
   int data; //4 bytes 
   struct Node* next;  //4 bytes 
};
void print(struct Node* t){
   while(t!=NULL){
       printf("%d ",t->data);
       t=t->next;
   }
}
struct Node* insert(struct Node *head,int value){
    struct Node *temp1=(struct Node*)malloc(sizeof(struct Node));
    temp1->data=value;
    if(head!=NULL){
    temp1->next=head;
    }
    head=temp1;
    return head;
}
int main()
{
    struct Node* head;
    head=NULL;
    struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=100;
    temp->next=NULL;
    head=temp;
    print(head);
    int x,i,n;
    printf("Enter the number of items you want to insert");
    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        printf("enter the item value");
        scanf("%d",&n);
        head=insert(head,n);
        print(head);
    }
    return 0;
}