/*#include <iostream>
using namespace std;
#define MAXSIZE 100
int a[MAXSIZE];
int listSize=0;

void insert(int data,int pos){
      if(pos>=1 && pos<=listSize+1){
        int i;
        for( i=listSize;i>=pos;i--){
            a[i]=a[i-1];
        }
        a[i]=data;
        listSize++;
      }
      else cout<<"Invalid position";
}
void remove(int data){
    int index=-1;
     for(int i=0;i<listSize;i++){
        if(a[i]==data) {index=i;
        break;}
     }
     if(index!=-1){
     for(int i=index;i<listSize;i++){
        a[i]=a[i+1];
     }
     listSize--;
     cout<<"data removed successfully"<<endl;
     }
     else cout<<"data not found for removing purpose"<<endl;

}
void search(int data){
    for(int i=0;i<listSize;i++){
        if(a[i]==data) {cout<<"Data found at position:"<<i+1<<endl;
        break;
        return;
        }
    }
    cout<<"data not found"<<endl;
    

}
bool isEmpty(){
    if(listSize==0) return true;
    else return false;
}
void display(){
    if(!isEmpty()){
    for(int i=0;i<listSize;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    }
}
void printReverse(){
  if(!isEmpty()){
    for(int i=listSize-1;i>=0;i--){
        cout<<a[i]<<" ";
    }
    cout<<endl;
  }
}




int main(){
   int N, queryType, data, position;
   cin >> N;
   for(int query = 1; query <= N; query++)
{
      cin >> queryType;
      switch(queryType)
{
      case 1:
       cin >> data >> position;
        insert(data, position);
         break;
          case 2: 
        cin >> data;
          remove(data);
           break;
case 3:
       cin >> data;
          search(data);
           break;
case 4:
display();
break;
case 5:
printReverse();
break;
}
}
return 0;
}
*/

/*
31
1 10 1
1 20 2
1 30 3
1 40 1
1 50 1
4
5
3 10
3 20
3 30
3 40
3 50
3 60
2 10
4
2 20
4
2 30
4
2 40
4
2 50
4
2 60
4
1 100 1
1 200 1
1 300 3
1 400 5
4
5
Output:
50 40 10 20 30
30 20 10 40 50
Data found at the position 3
Data found at the position 4
Data found at the position 5
Data found at the position 2
Data found at the position 1
Data not found
50 40 20 30
50 40 30
50 40
50
List is Empty
Data not found
List is Empty
Invalid Position
200 100 300
300 100 200
*/


/*

#include <iostream>
using namespace std;
#define MAX 5
int stack[MAX];
int top=-1;

bool isEmpty(){
    if(top==-1) return true;
    else return false;
}
bool isFull(){
    if(top>=MAX-1) return true;
    else return false;
}
void push(int data){
    if(!isFull()){
       stack[++top]=data;
    }
    else cout<<"Stack is Full Oveflow ";
}
int peek(){
     if(!isEmpty()) return stack[top];
     else {
        cout<<"Stack is empty"<<endl;
        return 0;
     }
}
int pop(){
    if(!isEmpty()) {
        int prevtop=stack[top];
        stack[top]=0;
        top--;
        return prevtop;
    }
    else {
        cout<<"Stack is Empty underflow"<<endl;
        return 0;
    }
}

void display(){
    if(!isEmpty()){
        for(int i=0;i<=top;i++){
            cout<<stack[i]<<" ";
        }
    }
}
int main(){
   int N,option,value;
cin>>N;
for(int ctr=0; ctr<N; ctr++)
{
cin>>option;
switch(option)
{
case 1:
 cin>>value;
  push(value);
  break;
  case 0:
   cout<<peek()<<endl;
   break;
  case -1:
  cout<<pop()<<endl;
  break;
}
}
  display();
return 0;

}
*/
/*
#include <iostream>
using namespace std;

class Node{
    public:
     int data;
     Node* next;

     Node(int data){
        this->data=data;
        this->next=NULL;
     }
};

class Stack{
    public :
     Node* head;
     Stack(){
        head=NULL;
     }
     bool isEmpty();
     void push(int);
     int peek();
     int pop();
};
int Stack::pop(){
  if(!isEmpty()){
    Node* temp=head;
    int data=temp->data;
    head=head->next;
    free(temp);
    return data;

  }
  else {
    cout<<"stack is Empty underflow"<<endl;
  }
}
int Stack::peek(){
    if(!isEmpty()){
        return head->data;
    }
    else {
        cout<<"Stack is Empty"<<endl;
        return 0;
    }
}
 bool Stack::isEmpty(){
      if(head==NULL) return true;
      else return false;
}

void Stack::push(int data){
    Node *newnode=new Node(data);
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
        //the elements are addede from right to left and heading is moving towards left while
        //inserting 
    }

}

void display(Stack s){
      Node* temp=s.head;
      if(!s.isEmpty()){
      while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
      }
      }
}

int main(){
  
    Stack s= Stack();
int N,queryType,data;
cin>>N;
for(int query=1;query<=N;query++)
{
cin>>queryType;
switch(queryType)
{
case 1:
cin>>data;
s.push(data);
break;
case 2:
if(!s.isEmpty())
{
cout<<"Popped Element: "<<s.pop()<<endl;
}
case 3:
if(!s.isEmpty())
{
cout<<"Top Element: "<<s.peek()<<endl;
}
else
{
s.peek();
}
break;
case 4:
display(s);
break;
}
}
return 0;
      
}
*/

/*

//array implementation of queue
#include <iostream>
using namespace std;
#define MAXSIZE 5
int queue[MAXSIZE];
int qsize=0;
int front=0;
bool isEmpty(){
    if(qsize==0) return true;
    else return false;
}
bool isFull(){
    if(qsize>=MAXSIZE) return true;
    else return false;
}
 void add(int data)
{
    if(!isFull()){
        queue[qsize]=data;
        qsize++;
    }
    else {
        cout<<"Queue is Full"<<endl;
    }
}

int peek(){
    if(!isEmpty()){
        return queue[front];
    }
    else {
        cout<<"queue is empty"<<endl;
        return 0;
    }
}
int poll(){
    if(!isEmpty()){
        int i;
        int data=queue[front];
        for( i=front;i<qsize-1;i++){
             queue[i]=queue[i+1];
        }
        qsize--;
        return data;
    }
    else {
        cout<<"Queue is Empty"<<endl;
        return 0;
    }
}
int main(){
  

                  int N, option, value;
               cin>>N;
                for(int ctr= 0; ctr<N; ctr++){
cin >> option;
switch(option){
case 1:
cin>> value;
       add(value);
break;
case 0:
        cout<<peek() <<endl;
break;
case -1:
          cout<<poll()<<endl;
break;
}
}
return 0;
}
*/


//Linked list implementation of queue

// #include <iostream>
// using namespace std;
// class Node{
//     public :
//   int data;
//   Node* next;
//   Node(int data){
//     this->data=data;
//     next=NULL;
//   }
// };
// class SinglyLinkedList{
//    public:
//       Node* head;
//       Node* tail;
//       SinglyLinkedList(){
//         head=NULL;
//         tail=NULL;
//       }
//     void append(int data);
//   void insert(int prevdata,int data);
//   int deleteNode(int data);
//   int search(int data);
//   void printList();    
// };


// int main(){
// SinglyLinkedList singlyLinkedList=SinglyLinkedList();
// int N,queryType,preData,data;
// cin>> N;
// for(int query=1;query<=N;query++)
// {
// cin>> queryType;
// switch(queryType)
// {
// case 1:
// cin>> data;
// singlyLinkedList.append(data);
// break;
// case 2:
// cin>>preData>> data;
// singlyLinkedList.insert(preData,data);
// break;
// case 3:
// cin>> data;
// cout<< singlyLinkedList.deleteNode(data);
// break;
// case 4:
// cin>> data;
// cout<< singlyLinkedList.search(data)<<endl;
// break;
// case 5:
// singlyLinkedList.printList();
// }
// }
// return 0;


// }




// binary search tree

// #include <iostream>
// using namespace std;
// struct bstnode{
//    int data;
//    bstnode* right;
//    bstnode* left;
// };
// //struct bstnode* root=NULL;
// struct bstnode* getnewnode(int data){
//     bstnode* newnode=(struct bstnode*)malloc(sizeof(struct bstnode));
//     newnode->data=data;
//     newnode->right=newnode->left=NULL;
//     return newnode;
// }
// bstnode* findmin(bstnode* root){
//     if(root==NULL){
//         cout<<"tree is empty error"<<endl;
//         return NULL;
//     }
//     else if(root->left==NULL){
//            return root;
//     }
//     findmin(root->left);
// }
// bstnode* findmax(struct bstnode* root){
//     if(root==NULL){
//         cout<<"tree is empty sorry"<<endl;
//         return NULL;
//     }
//     else if(root->right==NULL){
//         return root;
//     }
//     findmax(root->right);
// }
// bstnode* insert(struct bstnode* root,int data){
    
//        bstnode* newnode=getnewnode(data);
//        if(root==NULL){
//         root=newnode;
//         return root;
//        }
//        else if(root->data > data){
//                 root->left=insert(root->left,data);
//                 return root;
//        }
//        else {
//         root->right=insert(root->right,data);
//         return root;
//        }
// }
// void preorder( bstnode * root){
//    // cout<<"df"<<endl;
//     if(root==NULL) return;
//     cout<<root->data<<" ";
//     preorder(root->left);
//     preorder(root->right);
// }
// bstnode* deleteNode(struct bstnode* root,int data){
//          if(root==NULL) return root;
//          else if(root->data > data){
//             root->left=deleteNode(root->left,data);
//          }
//          else if(root->data < data){
//             root->right=deleteNode(root->right,data);
//          }
//          else {  //we found the node with data 
//                 //case 1 no child
//                 if(root->right==NULL && root->left==NULL){
//                     int temp=root->data;
//                     delete root;
//                     cout<<temp<<" is deleted!"<<endl;
//                     root=NULL;
//                     return root;
//                 }
//                 //case 2 one child either left or right
//                 else if(root->right==NULL){
//                     bstnode* temp=root;
//                     int tempdata=temp->data;
//                     root=root->left;
//                     delete temp;
//                     cout<<root->data<<"  is deleted!"<<endl;
//                     return root;
//                 }
//                 else if(root->left==NULL){
//                     bstnode* temp=root;
//                     int tempdata=temp->data;
//                     root=root->right;
//                     delete temp;
//                     cout<<root->data<<" is deleted!"<<endl;
//                     return root;
//                 }
//                 //case 3 two childs replace with the min from right sub tree

//                 else {
//                      struct bstnode* temp=findmin(root->right);
//                      root->data=temp->data;
//                      root->right=deleteNode(root->right,temp->data);
                     
//                 }
//          }
// }
// int main(){
//     struct bstnode* root=NULL;
//   int n;
//   int choice;
//   int data;
//   cin>>n;
//   for(int i=0;i<n;i++){
//     cin>>choice;
//     switch (choice)
//     {
//     case 1:
//     cin>>data;
//     root=insert(root,data);
//         break;
//     case 2:
//     cin>>data;
//     root=deleteNode(root,data);
//         break;
//     case 3:
//      preorder(root);
//         break;
//     default:
//         break;
//     }
//   }

// }





// #include <iostream>

// using namespace std;


// class minHeap{
//   public: 
//     int *harr;
//     int capacity;
//     int heap_size;
    
//     minHeap(int n){
//         capacity=n;
//         harr=new int[n];
//     }
//     void insert(int);
//     int extractMin();
//     void Heapify(int);
//     void display();
//     int parent(int i){
//         return (i-1)/2;
//     }
//     int left(int i) {
//         return 2*i+1;
//     }
//     int right( int i){
//         return 2*i+2;
//     }
// };
// void minHeap::display(){
//     if(heap_size==0){
//         cout<<"Heap is empty"<<endl;
//     }
//     else{
//         for(int i=0;i<heap_size;i++){
//             cout<<harr[i]<<" ";
//         }        
//         cout<<endl;
//     }
// }
// void minHeap::insert(int data){
//     cout<<"ad";
//     if(heap_size==capacity){
//         cout<<"Overflow heap is full"<<endl;
//         return;
//     }
//     heap_size++;
//     int i=heap_size-1;
//     harr[i]=data;
//     while(i!=0 && harr[parent(i)] > harr[i])
//     {
//         swap(harr[parent(i)],harr[i]);
//         i=parent(i);
//     }
// }
// void minHeap::Heapify(int i){
//     int l=left(i);
//     int r=right(i);
//    int smallest=i;
//     if(l<heap_size && harr[l] < harr[smallest] ){
//         smallest=l;
//     }
//     if(r<heap_size && harr[smallest] > harr[r]){
//         smallest=r;
//     }
//     if(smallest!=i){
//         swap(harr[i],harr[smallest]);
//         Heapify(0);
//     }
// }
// int minHeap::extractMin(){
//     if(heap_size<=0) return 0;
    
//     else if(heap_size==1){
//         heap_size--;
//         return harr[0];
//     }
//     else{
//         int root=harr[0];
//         harr[0]=harr[heap_size-1];
//         heap_size--;
//         int smallest=root;
//         Heapify(smallest);
        
//         return root;
//     }
// }

// void swap(int &x,int & y){
//     int temp;
//     temp=x;
//     x=y;
//     y=temp;
// }
// int main()
// {
//     minHeap m(100);
//     int n;
//     cin>>n;
//     int data;
//     int choice;
//     for(int i=0;i<n;i++){
//         cin>>choice;
//         cout<<"hhe";
//         switch(choice){
//             case 1:
//             cin>>data;
//              //insert
//              m.insert(data);
//              break;
//              case 2:
//               //extractMin
//               cout<<m.extractMin()<<endl;
//               break;
//               case 3:
//               //display
//               m.display();
//               break;
//               default:
//               break;
//         }
//     }

//     return 0;
// }


           


#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
};

struct Node* insert(struct Node* head, int coeff, int pow) {
    struct Node* temp = head;
    struct Node* newnode = new Node;
    newnode->coeff = coeff;
    newnode->pow = pow;
    newnode->next = NULL;

    if (head == NULL || pow > head->pow) {
        newnode->next = head;
        head = newnode;
    } else {
        while (temp->next != NULL && temp->next->pow >= pow) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}

void print(struct Node* head) {
    if (head == NULL) {
        cout << "No polynomial." << endl;
    } else {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->coeff != 0) {
                if (temp->coeff > 0) {
                    if (temp != head)
                        cout << "+";
                    if (temp->coeff != 1)
                        cout << temp->coeff;
                } else {
                    if (temp->coeff == -1)
                        cout << "-";
                    else
                        cout << temp->coeff;
                }
                cout << "x^" << temp->pow << " ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
}

struct Node* create(Node* head) {
    string polynomial;
    cout << "Enter the polynomial: ";
    cin.ignore();
    getline(cin, polynomial);

    string term;
    int coeff, pow;
    int sign = 1;
    for (char ch : polynomial) {
        if (ch == '+' || ch == '-') {
            if (!term.empty()) {
                if (term[0] == 'x') {
                    coeff = sign;
                    pow = 1;
                } else {
                    int pos = term.find('x');
                    if (pos == string::npos) {
                        coeff = sign * stoi(term);
                        pow = 0;
                    } else {
                        string coeffStr = term.substr(0, pos);
                        if (coeffStr.empty() || coeffStr == "+")
                            coeff = sign;
                        else if (coeffStr == "-")
                            coeff = -sign;
                        else
                            coeff = sign * stoi(coeffStr);
                        if (pos == term.length() - 1)
                            pow = 1;
                        else
                            pow = stoi(term.substr(pos + 2));
                    }
                }
                head = insert(head, coeff, pow);
            }
            term.clear();
            sign = (ch == '+') ? 1 : -1;
        } else {
            term += ch;
        }
    }
    if (!term.empty()) {
        if (term[0] == 'x') {
            coeff = sign;
            pow = 1;
        } else {
            int pos = term.find('x');
            if (pos == string::npos) {
                coeff = sign * stoi(term);
                pow = 0;
            } else {
                string coeffStr = term.substr(0, pos);
                if (coeffStr.empty() || coeffStr == "+")
                    coeff = sign;
                else if (coeffStr == "-")
                    coeff = -sign;
                else
                    coeff = sign * stoi(coeffStr);
                if (pos == term.length() - 1)
                    pow = 1;
                else
                    pow = stoi(term.substr(pos + 2));
            }
        }
        head = insert(head, coeff, pow);
    }
    return head;
}

void polyAdd(Node* head1, Node* head2) {
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* result = NULL;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->pow == ptr2->pow) {
            result = insert(result, ptr1->coeff + ptr2->coeff, ptr2->pow);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if (ptr1->pow > ptr2->pow) {
            result = insert(result, ptr1->coeff, ptr1->pow);
            ptr1 = ptr1->next;
        } else if (ptr1->pow < ptr2->pow) {
            result = insert(result, ptr2->coeff, ptr2->pow);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL) {
        result = insert(result, ptr1->coeff, ptr1->pow);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL) {
        result = insert(result, ptr2->coeff, ptr2->pow);
        ptr2 = ptr2->next;
    }

    cout << "Polynomial Addition: ";
    print(result);
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    cout << "Enter the first polynomial\n";
    head1 = create(head1);

    cout << "Enter the second polynomial\n";
    head2 = create(head2);

    polyAdd(head1, head2);

    return 0;
}
