#include <iostream>
#define MAXSIZE 5
using namespace std;
int arr[MAXSIZE] , top=-1;
bool isEmpty(){
    if(top==-1) return 1;
    else return 0;
}
bool isFull(){
    if(top==MAXSIZE-1 ) return 1;
    else return 0;
}
void push(int num){
    if(!isFull()){
        arr[top++]=num;
  }
    else {cout<<"Overflow"<<endl; return;}
}
int pop()
{   
    if(isEmpty()) 
    {cout<<"Underflow"<<endl;
    return 0;}
    else{
        return arr[top];
    arr[top--]=0;
    }
}
 int peek(){
     return arr[top];
 }


void display()
 { if(!isEmpty()) 
 { for(int index = 0; index <= top; index++)
  { cout << arr[index] << " "; } }
   else { cout << "Stack is empty"; } 
   cout<<endl; } 
   int main() 
   { int N,option,value;
    cin >> N; 
    for(int ctr=0; ctr<N; ctr++) 
    { cin >> option;
     switch(option) 
     { case 1:
      cin >> value; push(value); break;
       case 0: 
       cout << peek() << endl; break;
    case -1: 
    cout << pop() << endl; break; }
         } 
         display();
          return 0;
           }