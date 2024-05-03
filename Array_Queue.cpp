#include <iostream>
using namespace std;
#define MAXSIZE 5
//queue is first in first out insertion at the end
//deletion at the front
//queue implementation using  array
int queue[MAXSIZE];
int front=-1;
int rear=-1;
//rear is index value in queue
bool isEmpty(){
  if(rear==-1 && front==-1) return 1;
  else return 0;
}
bool isFull(){
   if(rear>=MAXSIZE-1) return 1;
   else return 0;
}
void enqueue(int data){
    if(rear==MAXSIZE-1) cout<<"Overflow"<<endl;
    else if(front==-1 && rear==-1)  //for ist element insertion
    {
        front=rear=0;
        queue[rear]=data;
    }
    //always insert the elements using rear end-> queue[rear]=data
    else{ //for inserting after many elements
          rear++;
          queue[rear]=data;
    }
}
void dequeue(){
     if(front==-1 && rear==-1) cout<<"Underflow "<<endl;
     else if(front==rear){ 
           front=rear=-1;//pointing to only one element in the queue
               //after deleting the last element set front=rear=-1  the queue is empty
     }
     else{
        cout<<"deleted element :"<<queue[front]<<endl;
        front++; //deleting at the front
     } //the queue is from front to rear
}
void peek(){
    if(!isEmpty()){
        cout<<"Top element from queue is :"<<queue[front]<<endl;
    }
    else{
        cout<<"queue is Empty"<<endl;
    }
}
void display(){
    if(!isEmpty()){
      for(int i=front;i<=rear;i++){
        cout<<queue[i]<<" ";
      }
      cout<<endl;
    }
    else cout<<"Queue is Empty"<<endl;
}

int main(){
   enqueue(12);
   enqueue(14);
   enqueue(18);
   enqueue(15);
   enqueue(16);
   display();
   dequeue();
   

}
