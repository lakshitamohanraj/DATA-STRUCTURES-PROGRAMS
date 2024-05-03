#include <iostream> 
using namespace std; 
class Node { 
    public: 
    int data;
     Node *next; 
     Node(int val) 
     { data = val; next = NULL; } 
     }; 
     class SinglyLinkedList { 
        public: // head is the pointer to the head of the singly linked list 
        // tail is the pointer to the tail of the singly linked list
         Node *head, *tail; 
         SinglyLinkedList() { head = NULL; tail = NULL; } 
         bool isEmpty(); 
         void append(int); 
         void insert(int, int);
          void deleteNode(int);
           bool search(int); 
           void printList(); }; 

  bool SinglyLinkedList::isEmpty(){
    if(head==NULL) return true;
    else return false;
}
void SinglyLinkedList::append(int data){
    Node* newnode=new Node(data);
    if(this->isEmpty()){
        head=newnode;
        tail=newnode;
        return;
    }
    /*else if(head!=NULL && tail!=NULL){
        tail->next=newnode;
        tail=newnode;*/
    
        tail->next=newnode;
        tail=newnode;

}
void SinglyLinkedList::insert(int prevData,int data){
    Node* newnode=new Node(data);
    Node* temp=head;
    if (!this->search(prevData)){
        cout<<"previous val not in list"<<endl;
    }
    // while(temp!=NULL){
    //     if(temp->data==prevData){
    //         break;
    //     }
    //     temp=temp->next;
    // }
    // if(temp!=NULL && tail!=temp){
    //     newnode->next=temp->next;
    //     temp->next=newnode;
    // }
    else if(head->data==prevData){
        newnode->next=head->next;
        head->next=newnode;
        head=newnode;
    }
    else {
        Node* t=NULL;
        while(temp!=NULL){
            if(temp->data==prevData){
                t=temp;break;
            }
            temp=temp->next;
        }
        newnode->next=t->next;
        t->next=newnode;
    }
    // else if(!this->search(prevData)){
    //     cout<<"previous val not in list"<<endl;
    //     delete newnode;
    // }
}
void SinglyLinkedList::deleteNode(int data){
    Node* temp=head;
    Node* Del=NULL;
   int c=0;
   if(!this->search(data)){
       cout<<"val not in list"<<endl;
       return;
   }
    if(temp->data==data && head!=NULL){ //at the head delete 
        head=head->next;
        delete temp;
        return;
    }
else if(head!=NULL && temp->data!=data) {
    
    
    while(temp->next!=NULL){
        if(temp->next->data==data){
            Del=temp->next;
            temp->next=temp->next->next;
            c++;
            delete Del;
            break;
        }
        temp=temp->next;
    }
    
}


}
bool SinglyLinkedList::search(int data){
    Node* temp=head;
    bool flag=false;
    while(temp!=NULL){
        if(temp->data==data) {
            flag=true;
            break;
        }
        temp=temp->next;
    }
    return flag;
}





    void SinglyLinkedList::printList()
     { 
        if(isEmpty()) { cout << "list is empty" << endl; return; }
         Node *temp = head; 
         while(temp != tail) 
         { cout << temp->data << " "; temp = temp->next; } 
         cout << tail->data << endl; }
          int main() 
          { 
            SinglyLinkedList singlyLinkedList = SinglyLinkedList();
             int N, queryType, prevData, data; 
             cin >> N; 
             for (int query = 1; query <= N; query++) 
             { cin >> queryType; 
             switch (queryType) 
             { case 1: cin >> data;
              singlyLinkedList.append(data);
               break;  
               case 2: 
               cin >> prevData >> data; 
               singlyLinkedList.insert(prevData, data);
                break; 
                case 3:
                 cin >> data;
                  singlyLinkedList.deleteNode(data);
                   break;
                    case 4:
                     cin >> data; 
                     cout << singlyLinkedList.search(data) << endl; 
                     break; 
                     case 5: 
                     singlyLinkedList.printList(); 
                     } 
                     } 
                     return 0; }



                     /*

                    the sample output and input looks like this.
                     The query type can be one of the following types.
                      1 - append 
                      2 - insert
                       3 - deleteNode 
                       4 - search 
                       5 - printList
                        Example Input/Output 1:
                         Input: 
                         31 
                         1 10 
                         1 30 
                         1 50 
                         5 
                         2 10 20
                          2 30 40 
                          2 50 60 
                          2 70 80 
                          5 
                          4 10 
                          4 20 
                          
                          4 70 
                          4 80 
                          5 
                          3 10 
                          5 
                          3 20 
                          5 
                          3 30 
                          5 
                          3 40 
                          5 
                          3 50 
                          5 
                          3 60 
                          5 
                          3 70 
                          5 
                          1 100 
                          1 200 
                          5 
                          Output: 
                          10 30 50 
                          previous val not in list 
                          10 20 30 40 50 60 
                          1 
                          1 
                          
                          0 
                          0 
                          10 20 30 40 50 60 
                          20 30 40 50 60 
                          30 40 50 60 
                          40 50 60 
                          50 60 
                          60 
                          list is empty 
                          val not in list 
                          list is empty 
                          100 200
                     
                     
                     */