#include <iostream>
using namespace std;
/*polynomial addition using linked list */
// coefficient| power |nextlinking

//the power higher are calculated  1st inserted before the smaller power
struct Node{
   int coeff;
   int pow;
   Node* next;
};

struct Node* insert(struct Node* head,int coeff,int pow){
      struct Node* temp=head;
      struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
      newnode->coeff=coeff;
      newnode->pow=pow;
      newnode->next=NULL;
      //1st node as well second node inserted and checked
      if(head==NULL || pow > head->pow){
        newnode->next=head;
        head=newnode;
      }
      else {
        while(temp->next!=NULL && temp->next->pow >= pow){
              temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
      }
      return head;
}

void print(struct Node* head){
    if(head==NULL){
        cout<<"No polynomial ."<<endl;
    }
    else {
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->coeff<<"x^"<<temp->pow<<" ";
            temp=temp->next;
            if(temp!=NULL) cout<<"+";
            else cout<<endl;
        }
    }
}
struct Node* create(Node* head){
    int coeff;
    int pow;
    int n;
    cout<<"Enter the number of terms"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the coefficient of term :"<<i+1;
        cin>>coeff;
        cout<<"Enter the expoenent for term :"<<i+1;
        cin>>pow;
        head=insert(head,coeff,pow);
    }
    return head;

}
void polyAdd(Node* head1,Node* head2){
    Node* ptr1=head1;
    Node* ptr2=head2;
    Node* result=NULL;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->pow==ptr2->pow){
            result=insert(result,ptr1->coeff+ptr2->coeff,ptr2->pow);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->pow > ptr2->pow){
            result=insert(result,ptr1->coeff,ptr1->pow);
            ptr1=ptr1->next;
        }
        else if(ptr1->pow < ptr2->pow){
            result=insert(result,ptr2->coeff,ptr2->pow);
             ptr2=ptr2->next;
        }
    }
    

//needed some codes to check for some leftover nodes to be added
//sometimes ptr1 can be null but ptr2 cant same as vice versa
while(ptr1!=NULL){
   result=insert(result,ptr1->coeff,ptr1->pow);
   ptr1=ptr1->next;
}
while(ptr2!=NULL){
    result=insert(result,ptr2->coeff,ptr2->pow);
    ptr2=ptr2->next;
}

cout<<"Added polynomial is :\n";
print(result);
}


int main(){
   struct Node* head1=NULL;
   struct Node* head2=NULL;
   cout<<"Enter the first polynomial \n";
   head1=create(head1);
   cout<<"Enter the second polynomial \n";
   head2=create(head2);

   polyAdd(head1,head2);


  return 0;
}