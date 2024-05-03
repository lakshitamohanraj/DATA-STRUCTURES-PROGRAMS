#include <iostream>
//ARRAY IMPLEMENTATION OF LIST ADT
 #define MAXSIZE 100
  using namespace std;
   int arr[MAXSIZE], listSize = 0; 
   //listsize is the number of elements present in arr
   
      bool isEmpty(){
            if(listSize==0) return true;
            else return false;
      } 
     void insert(int num,int pos){
        if(listSize==MAXSIZE)
        {
            cout<<"list is full"<<endl;
            return;
        }
        int i=0;
        
            if(pos>=1 && pos<=listSize+1)//we cant able to add elements above the list size+1 causes empty boxes
            {
        for( i=listSize-1;i>=pos-1;i--) //pos-1 gives index value
        { 
            arr[i+1]=arr[i]; //arr[i]=arr[i-1] for starts from i=listSize
        }
            }
        
        arr[i+1]=num;// for the 1st pos i=-1 then i+1=0
        listSize++;
     }

      void remove(int data) 
      {
          int index;
          for(int i=0;i<listSize;i++){
            if(data==arr[i]){
                index=i;
            }
          }
          for(int j=index;j<listSize-1;j++){
                    arr[j]=arr[j+1];
          }
          listSize--;
       } 
      void search(int data)
      { 
          for(int i=0;i<listSize;i++){
            if(data==arr[i]){
                cout<<"found at "<<i+1<<endl;
            }
          }
      } 
      void display(){
        for(int i=0;i<listSize;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
      }


       void printReverse() 
       { 
        if(!isEmpty()) 
       { 
        for(int index = listSize-1; index >= 0; index--)

       { cout << arr[index] << " "; } 
       cout << endl; 
       } 
       else 
       { cout << "List is Empty" << endl; } 
       }

int main() 
       { 
        
       insert(12,1);
       insert(13,2);
       insert(2,3);
       insert(14,4);
       insert(15,5);
       insert(17,6);

       display();
    //    printReverse();


       search(2);
       remove(12);
       remove(14);
        display();
       cout<<listSize<<" ";
       return 0; 
           }